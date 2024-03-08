#ifndef SQUARE_HPP
# define SQUARE_HPP

#include <SFML/Graphics.hpp>
#include <stdlib.h> //Pour rand et srand (seed rand)
#include <time.h> //Pour time (seed rand)
#include <iostream>

using namespace sf;
using namespace std;

class Square : public RectangleShape {
	private:
		int _squareType;
		bool _isDiscovered;

	public:
		Square(const Vector2f &size);
		~Square();

		void setRandSquareType(bool isGameStart, int &bombCount);
		void setDiscovered();
		const int &getSquareType() const;
		const bool &isDiscovered() const;
};

#endif

