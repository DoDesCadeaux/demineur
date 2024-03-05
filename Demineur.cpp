#include "Demineur.hpp"

Demineur::Demineur() {
		for (size_t i = 0; i < 10; i++) {
			for (size_t j = 0; j < 10; j++) {
				RectangleShape square(Vector2f(32.0f, 32.0f));

				square.setFillColor(Color(117, 114, 114));
				square.setOutlineThickness(1.0f);
				square.setOutlineColor(Color::Red);

				square.setPosition(j * 32, i * 32);
				this->_squares.push_back(square);
			}
		}
}

Demineur::~Demineur() {}

vector<RectangleShape> &Demineur::getSquares() {
	return this->_squares;
}

void Demineur::setSquareColor(RectangleShape &square) {
	square.setFillColor(Color::Green);
}
