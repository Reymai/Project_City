#include "game.h"

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	//load level
	int level[] = { // 0 - grass, 1 - market, 2 - road, 3 - first grade house, 4 - second grade house, 5 - third grade house
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
	Economics economics (1500, ptrLevel);
	Building building;
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

		economics.paying (building.build (window, economics, ptrLevel, map));
		economics.paying (building.housesUpdate (ptrLevel, economics, map));
		map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), ptrLevel, 25, 12);

		economics.update ();
		
		ui.update (economics, building, window);

		window.clear ();
		window.setView (view);
		window.draw (background);
		window.draw (map);
		window.draw (ui);
		window.display ();
	}
	return EXIT_SUCCESS;
}
