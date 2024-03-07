#include "Square.hpp"

Square::Square(const Vector2f &size) : RectangleShape(size) {
	this->_isDiscovered = false;
	this->_squareType = 0;
}

Square::~Square() {}

void Square::setRandSquareType(bool isGameStart) {
	if (isGameStart == true) 
		this->_squareType = 0;
	else {
		int bomb = rand() % 3 + 1;
		this->_squareType = (bomb > 1) ? 0 : -1;
	}
}

const int &Square::getSquareType() const {
	return this->_squareType;
}

void Square::setDiscovered() {
	this->_isDiscovered = true;
}

const bool &Square::isDiscovered() const {
	return this->_isDiscovered;
}

