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
	sf::Texture *tileset;

public:
	int load(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
	void movement(sf::Keyboard& keyboard, sf::View& view);
};