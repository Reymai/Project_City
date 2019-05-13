#include "game.h"

#include <tmxlite/Layer.hpp>
#include <tmxlite/TileLayer.hpp>
#include <tmxlite/ImageLayer.hpp>
#include <iostream>

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	// load map
	if (!map.load("media/map.tmx")) {
		return EXIT_FAILURE;
	}
	Game::draw(window);
}

int Game::draw(sf::RenderWindow& window) {
	//creating background
	sf::Sprite background(background);
	const auto& layers = map.getLayers();
	const auto& tilesets = map.getTilesets();
	const auto& orientation = map.getOrientation();

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		window.clear();
		window.draw(background);
		window.display();
	}
	return EXIT_SUCCESS;
}
