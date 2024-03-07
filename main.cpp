#include "Demineur.hpp"

int main() {
	RenderWindow window(VideoMode(320, 320), "Demineur");
	Demineur demineur;
	srand (time(NULL));

	Texture mine;
	if (!mine.loadFromFile("mine.png"))
		return -1;

	while (window.isOpen()) { //Main Loop
		Event event;

		if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) {
			system("leaks demineur");
			cout << "Fermeture" << endl;
			window.close();
		}
		window.clear(Color::Black);

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i mouseLocalPosition = Mouse::getPosition(window);

					for (auto &square : demineur.getSquares()) {
						if (demineur.getGameStart()) 
							square.setRandSquareType(true);
						else
							square.setRandSquareType(false);
						if (square.getGlobalBounds().contains(mouseLocalPosition.x, mouseLocalPosition.y) && !square.isDiscovered()) {
							square.setDiscovered();
							if (square.getSquareType() == -1)
								demineur.setSquareTexture(square, &mine);
							else
								demineur.setSquareColor(square, Color::Green);
							demineur.setGameStart(false);
						}
					}
				}
			}
		}

		for (const RectangleShape &square : demineur.getSquares())
			window.draw(square);

		window.display();
	}
	return 0;
}

