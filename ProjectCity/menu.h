#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Menu {
private:
	sf::Texture background;
	sf::Texture button;
	sf::Font font;
	sf::Music music;
	
public:
	int load(sf::RenderWindow& window);
	int draw(sf::RenderWindow& window);
	int buttons(sf::Sprite &button1, sf::Sprite &button2);
};

