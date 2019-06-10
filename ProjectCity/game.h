#pragma once

#include <STP/TMXLoader.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
private:
	sf::Texture background;
	sf::Music music;
	sf::Font font;

public:
	int load(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
	void movement(sf::Keyboard& keyboard, sf::View& view);
};

