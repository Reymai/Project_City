#include "game.h"
#include <iostream>

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	
	Game::draw(window);
}

int Game::draw(sf::RenderWindow& window) {
	//creating background 
	sf::Sprite background(background);

	tmx::TileMap map("media/map.tmx");

	map.ShowObjects();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		
		window.clear();
		window.draw(background);
		window.draw(map);
		window.display();
	}
	return EXIT_SUCCESS;
}
