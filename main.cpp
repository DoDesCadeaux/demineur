#include "Demineur.hpp"

int main() {
	RenderWindow window(VideoMode(640, 640), "DoSweeper");
	Demineur demineur;
	srand (time(NULL));

	//	demineur.printSquaresPositions(demineur.getSquaresPosition());

	Texture mineT, flagT, discoveredT, squareT;
	if (!mineT.loadFromFile("lostMine.png") || !flagT.loadFromFile("flag.png") 
			|| !discoveredT.loadFromFile("discovered.png") || !squareT.loadFromFile("square.png"))
		return -1;
	Font font;
	if (!font.loadFromFile("fira.ttf"))
		return -1;

	for (auto &square : demineur.getSquares())
		square.setTexture(&squareT);

	while (window.isOpen()) { //Main Loop
		Event event;


		window.clear(Color::Black);

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			else if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) {
				cout << "Fermeture" << endl;
				window.close();
			}
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i leftMousePos = Mouse::getPosition(window);

					for (auto &square : demineur.getSquares()) {
						if (demineur.getGameStart()) 
							square.setRandSquareType(true, demineur.getBombs());
						else
							square.setRandSquareType(false, demineur.getBombs());

						if (square.getGlobalBounds().contains(leftMousePos.x, leftMousePos.y) && !square.isDiscovered()) {
							square.setDiscovered();

							if (square.getSquareType() == -1)
								square.setTexture(&mineT);
							else
								square.setTexture(&discoveredT);

							demineur.setGameStart(false);
							vector<Square> *neighbors = demineur.getNeighborsByPosition(square.getPosition());
							size_t bombCount = 0;
							for (auto& neighbor : *neighbors) {
								if (neighbor.getSquareType() == -1) 
									bombCount++;
							}
							delete neighbors;
							if (bombCount == 1)
								square.setFillColor(Color::Red);
							else if (bombCount == 2)
								square.setFillColor(Color::Blue);
							else if (bombCount == 3)
								square.setFillColor(Color::Green);
							else if (bombCount == 4)
								square.setFillColor(Color::Black);
							else if (bombCount == 5)
								square.setFillColor(Color::Yellow);
						}
					}
				}
			}

			for (auto &square : demineur.getSquares())
				window.draw(square);

			window.display();
		}
	}
	return 0;
}

