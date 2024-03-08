#include "Demineur.hpp"

Demineur::Demineur() : _bombs(0), _isGameStart(true) {
	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j < 10; j++) {
			Square square(Vector2f(32.0f, 32.0f));

			square.setFillColor(Color(117, 114, 114));
			square.setOutlineThickness(1.0f);
			square.setOutlineColor(Color::Red);

			square.setPosition(j * 32, i * 32);
			this->_squares.push_back(square);
		}
	}
}

Demineur::~Demineur() {}

vector<Square> &Demineur::getSquares() {
	return this->_squares;
}

void Demineur::setSquareColor(Square &square,const Color &color) {
	square.setFillColor(color);
}

void Demineur::setSquareTexture(Square &square, const Texture *texture) {
	square.setTexture(texture);
}

bool &Demineur::getGameStart() {
	return this->_isGameStart;
}

vector<Vector2f> Demineur::getSquaresPosition() {

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

void Demineur::printSquaresPositions(const vector<Vector2f> &squaresPositions) {
	int i = 0;
	for (auto it = squaresPositions.begin(); it != squaresPositions.end(); ++it) {
		cout << "Square: " << i << " X: " << it->x << " Y: " << it->y << endl;
		i++;
	}
}



int &Demineur::getBombs() {
	return this->_bombs;
}

void Demineur::setBombs(int bombs) {
	this->_bombs = bombs;
}

void Demineur::setGameStart(bool start) {
	this->_isGameStart = start;
}

