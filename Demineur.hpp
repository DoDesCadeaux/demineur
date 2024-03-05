#ifndef DEMINEUR_HPP
# define DEMINEUR_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

using namespace std;
using namespace sf;

class Demineur {
	private:
		vector<RectangleShape> squares;

	public:
		Demineur();
		~Demineur();
};

#endif

