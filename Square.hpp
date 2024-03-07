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

	public:
		Square(const Vector2f &size);
		~Square();

		void setRandSquareType();
		const int &getSquareType() const;
};

#endif

