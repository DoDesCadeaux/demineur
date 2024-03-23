#include "Demineur.hpp"

int main() {
	RenderWindow window(VideoMode(640, 640), "DoSweeper");
	Demineur demineur;
	srand (time(NULL));

	Texture mineT, flagT, discoveredT, squareT;
	if (!mineT.loadFromFile("lostMine.png") || !flagT.loadFromFile("flag.png") 
			|| !discoveredT.loadFromFile("discovered.png") || !squareT.loadFromFile("square.png"))
		return -1;
	Font font;
	if (!font.loadFromFile("fira.ttf"))
		return -1;

	for (auto &square : demineur.getSquares())
		square.setTexture(&squareT);

	Texture oneT, twoT, threeT, fourT, unknownT;
	if (!oneT.loadFromFile("one.png") || !twoT.loadFromFile("two.png") || !threeT.loadFromFile("three.png") || !fourT.loadFromFile("four.png") || !unknownT.loadFromFile("unknown.png"))
		exit(1);

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

							demineur.setGameStart(false);
							vector<Square> *neighbors = demineur.getNeighborsByPosition(square.getPosition());
							size_t bombCount = 0;
							for (auto& neighbor : *neighbors) {
								if (neighbor.getSquareType() == -1) 
									bombCount++;
							}

							delete neighbors;

							if (square.getSquareType() == -1)
								square.setTexture(&mineT);
							else if (bombCount == 0)
								square.setTexture(&discoveredT);
							else {
								switch (bombCount) {
									case  1:
										square.setTexture(&oneT);
										break;
									case 2:
										square.setTexture(&twoT);
										break;
									case 3:
										square.setTexture(&threeT);
										break;
									case 4:
										square.setTexture(&fourT);
										break;
									default:
										square.setTexture(&unknownT);
										break;
								}
							}
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

