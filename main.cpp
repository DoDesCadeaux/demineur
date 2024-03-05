#include "Demineur.hpp"

vector<Vector2f> getSquaresPositions() {

	vector<Vector2f> squarePositions;

	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j < 10; j++) {
			RectangleShape square(Vector2f(32, 32));

			square.setPosition(j * 32, i * 32);
			squarePositions.push_back(square.getPosition());
		}
	}

	return squarePositions;
}

void printSquaresPositions(const vector<Vector2f> &squaresPositions) {
	int i = 0;
	for (auto it = squaresPositions.begin(); it != squaresPositions.end(); ++it) {
		cout << "Square: " << i << " X: " << it->x << " Y: " << it->y << endl;
		i++;
	}
}

int main() {
	RenderWindow window(VideoMode(320, 320), "Demineur");
	vector<Vector2f> squaresPositions = getSquaresPositions();
	vector<RectangleShape> squares;

	printSquaresPositions(squaresPositions);
	
	while (window.isOpen()) { //Main Loop
		Event event;

		if ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)) {
			cout << "Fermeture" << endl;
			window.close();
		}

		window.clear(Color::Black);


		for (size_t i = 0; i < 10; i++) {
			for (size_t j = 0; j < 10; j++) {
				RectangleShape square(Vector2f(32.0f, 32.0f));

				square.setFillColor(Color(117, 114, 114));
				square.setOutlineThickness(1.0f);
				square.setOutlineColor(Color::Red);

				square.setPosition(j * 32, i * 32);
				squares.push_back(square);
				window.draw(square);
			}
		}

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i mouseLocalPosition = Mouse::getPosition(window);
					for (auto &square : squares) {
						if (square.getGlobalBounds().contains(mouseLocalPosition.x, mouseLocalPosition.y))
							square.setFillColor(Color::Green);
					}
				}
			}
		}
		for (const RectangleShape &square : squares)
			window.draw(square);

		window.display();
	}


	return 0;
}

