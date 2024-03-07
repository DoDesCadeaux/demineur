#ifndef DEMINEUR_HPP
# define DEMINEUR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Square.hpp"

using namespace std;
using namespace sf;

class Demineur {
	private:
		vector<Square> _squares;
		int _bombs;


	public:
		Demineur();
		~Demineur();

		vector<Square> &getSquares();
		vector<Vector2f> getSquaresPosition();
		void setSquareColor(Square &square, const Color &color);
		void printSquaresPositions(const vector<Vector2f> &squaresPositions);
		const int &getBombs() const;
		void setBombs(int bombs);
};

#endif

