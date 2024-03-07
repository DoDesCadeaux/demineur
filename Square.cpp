#include "Square.hpp"

Square::Square(const Vector2f &size) : RectangleShape(size) {}

Square::~Square() {}

void Square::setRandSquareType() {
	int bomb = rand() % 3 + 1;

	this->_squareType = (bomb > 1) ? 0 : -1;
}

const int &Square::getSquareType() const {
	return this->_squareType;
}

