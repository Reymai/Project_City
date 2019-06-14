#include "game.h"
#include <Windows.h>

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	//load level
	int level[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};
	ptrLevel = level;
	//load map and tileset
	if (!map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), level, 25, 12))
		return EXIT_FAILURE;
	
	Game::draw(window);
}

int Game::draw (sf::RenderWindow &window) {
	//creating background 
	sf::Sprite background (background);
	Economics economics (100, ptrLevel);
	UI ui;
	ui.load ();

	//camera setup
	view.setSize (window.getSize ().x, window.getSize ().y);
	view.setCenter (window.getSize ().x / 2, window.getSize ().y / 2);

	map.move ((window.getSize ().x / 2) - 800, (window.getSize ().y / 2) - 384);			//25 * 64 = 1600	1600 / 2 = 800 | 12 * 64 = 768		768 / 2 = 384

	while (window.isOpen ()) {
		sf::Event event;
		while (window.pollEvent (event)) {
			// Close window
			if (event.key.code == sf::Keyboard::Escape) {
				window.close ();
			}
		}
		building (window, ptrLevel, economics);
		economics.update ();
		ui.update(economics);

		window.clear ();
		window.setView (view);
		window.draw (background);
		window.draw (map);
		window.draw (convex);
		window.draw (ui);
		window.display ();
	}
	return EXIT_SUCCESS;
}

void Game::building (sf::RenderWindow &window, int *Level, Economics economics) {
	if (mouse.isButtonPressed (mouse.Left)) {
		int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
		int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
		if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
			int toChange = xTile + yTile * 25;
			if (Level [toChange] == 0) {
				Level [toChange] = 2;
				economics.costs (10);
				map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
			}
		}
	}
	if (mouse.isButtonPressed (mouse.Right)) {
		int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
		int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
		if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
			int toChange = xTile + yTile * 25;
			if (Level [toChange] == 0) {
				Level [toChange] = 1;
				economics.costs (500);
				map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
			}
		}
	}
	if (mouse.isButtonPressed (mouse.Middle)) {
		int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
		int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
		if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
			int toChange = xTile + yTile * 25;
			if (Level [toChange] == 0) {
				Level [toChange] = 3;
				economics.costs (250);
				map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
			}
		}
	}
}