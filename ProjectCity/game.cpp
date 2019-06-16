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
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
	Economics economics (250, ptrLevel);
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
		economics.update ();
		building (window, ptrLevel, economics);
		ui.update(economics, window);
		housesUpdate (ptrLevel, economics);

		window.clear ();
		window.setView (view);
		window.draw (background);
		window.draw (map);
		window.draw (convex);
		window.draw (ui);
		window.display ();
	}
	delete ptrLevel;
	return EXIT_SUCCESS;
}

int Game::building (sf::RenderWindow &window, int *Level, Economics economics) {
	int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
	int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
	if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
		int toChange = xTile + yTile * 25;
		if (mouse.isButtonPressed (mouse.Left)) {
			if (Level [toChange] == 0) {
				Level [toChange] = 2;
				economics.costs (100);
			}
		}
		if (mouse.isButtonPressed (mouse.Right)) {
			if (Level [toChange + 1] == 2 || Level [toChange - 1] == 2 || Level [toChange + 25] == 2 || Level [toChange - 25] == 2) {
				if (Level [toChange] == 0) {
					Level [toChange] = 1;
					economics.costs (500);
				}
			}
		}
		if (mouse.isButtonPressed (mouse.Middle)) {
			if (Level [toChange + 1] == 2 || Level [toChange - 1] == 2 || Level [toChange + 25] == 2 || Level [toChange - 25] == 2) {
				if (Level [toChange] == 0) {
					Level [toChange] = 3;
					economics.costs (250);
				}
			}
		}
		if (mouse.isButtonPressed (mouse.Left) && mouse.isButtonPressed (mouse.Right)) {
			if (Level [toChange] == 1) {
				economics.incoming (500);
			}
			if (Level [toChange] == 2) {
				economics.incoming (100);
			}
			if (Level [toChange] == 3) {
				economics.incoming (250);
			}
			if (Level [toChange] == 4) {
				economics.incoming (350);
			}
			if (Level [toChange] == 5) {
				economics.incoming (650);
			}
			Level [toChange] = 0;
			
		}
		map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
	}
	return 0;
}

void Game::housesUpdate (int *Level, Economics economics) {
	for (int i = 0; i < 300; i++) {
		srand ((time (NULL)) + (rand() % 999));
		if (Level [i] == 3 && economics.getMoney() > 300) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						srand ((time (NULL)) + (rand () % 99999999999));
						if (rand () % 2) {
							economics.costs (100);
							Level [i] = 4;
							map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
						}
					}
				}
			}
		}
		if (Level [i] == 4 && economics.getMoney () > 700) {
			srand ((time (NULL)) + (rand () % 999));
			int j = 0;
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						srand ((time (NULL)) + (rand () % 99999999999));
						if (rand () % 2) {
							economics.costs (300);
							Level [i] = 5;
							map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
						}
					}
				}
			}	
		}
		if (Level [i] == 4 && economics.getMoney () < 100) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						Level [i] = 3;
						map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
					}
				}
			}
		}
		if (Level [i] == 5 && economics.getMoney () < 300) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						Level [i] = 4;
						map.load ("media/tiles/SimpleTileset.png", sf::Vector2u (64, 64), Level, 25, 12);
					}
				}
			}
		}
	}
}
