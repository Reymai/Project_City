#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "map.h"

class Game {
private:
	sf::Texture background;
	sf::Music music;
	sf::Font font;
	sf::Texture tileset;
	sf::View view;
	sf::Keyboard keyboard;
	sf::Mouse mouse;
	sf::ConvexShape convex;
	Map map;

	int *ptrLevel;

public:
	int load(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
	//void movement(sf::Sprite& background);
	void roadBuilding (sf::RenderWindow &window, int *Level);
};