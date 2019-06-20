#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "economics.h"
#include "map.h"

class Building {
private:
	sf::Keyboard keyboard;
	sf::Mouse mouse;
	unsigned int people;

	int humansInHouses (int *Level, int type);

public:

	Building ();

	int build (sf::RenderWindow &window, Economics economics, int *Level, Map map);
	int housesUpdate (int *Level, Economics economics, Map map);
	int getPeopleCount ();
};

