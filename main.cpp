#include "Demineur.hpp"

int main() {
	RenderWindow window(VideoMode(640, 640), "Demineur");
	Demineur demineur;
	srand (time(NULL));

//	demineur.printSquaresPositions(demineur.getSquaresPosition());

	Texture mineT, flagT, discoveredT, squareT;
	if (!mineT.loadFromFile("lostMine.png") || !flagT.loadFromFile("flag.png") 
			|| !discoveredT.loadFromFile("discovered.png") || !squareT.loadFromFile("square.png"))
		return -1;

	for (auto &square : demineur.getSquares())
		square.setTexture(&squareT);

	while (window.isOpen()) { //Main Loop
		Event event;

		if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) {
			cout << "Fermeture" << endl;
			window.close();
		}

		window.clear(Color::Black);

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
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
								demineur.setSquareTexture(square, &mineT);
							else
								demineur.setSquareTexture(square, &discoveredT);
							demineur.setGameStart(false);
						}
					}
				}
			}
		}

		for (auto &square : demineur.getSquares())
			window.draw(square);

		window.display();
	}
	return 0;
}

