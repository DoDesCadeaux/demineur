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
		bool _isGameStart;


	public:
		Demineur();
		~Demineur();

		vector<Square> &getSquares();
		vector<Vector2f> getSquaresPosition();
		bool &getGameStart(); 
		int &getBombs();
		void setSquareColor(Square &square, const Color &color);
		void setSquareTexture(Square &square, const Texture *texture);
		void setBombs(int bombs);
		void setGameStart(bool start);
		void printSquaresPositions(const vector<Vector2f> &squaresPositions);
};

#endif

