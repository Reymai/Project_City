#pragma once

#include <tmxlite/Map.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Game {
private:
	sf::Texture background;
	sf::Music music;
	sf::Font font;
	tmx::Map map;
public:
	int load(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
};

