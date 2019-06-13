#include "game.h"

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	//load level
	int level[] = {
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
		11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
	};
	ptrLevel = level;
	//load map and tileset
	if (!map.load ("media/tiles/Tileset.png", sf::Vector2u (64, 64), level, 25, 12))
		return EXIT_FAILURE;
	
	Game::draw(window);
}

int Game::draw(sf::RenderWindow& window) {
	//creating background 
	sf::Sprite background (background);

	//camera setup
	view.setSize (window.getSize().x, window.getSize ().y);
	view.setCenter (window.getSize ().x / 2, window.getSize ().y / 2);

	map.move ((window.getSize().x / 2) - 800, (window.getSize().y / 2) - 384);			//25 * 64 = 1600	1600 / 2 = 800 | 12 * 64 = 768		768 / 2 = 384

	
	/*convex setup
	convex.setPointCount (4);

	convex.setPoint (0, sf::Vector2f (0, 26));
	convex.setPoint (1, sf::Vector2f (52, 53.3f));
	convex.setPoint (2, sf::Vector2f (108.5.f, 26));
	convex.setPoint (3, sf::Vector2f (52, 0));*/

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.key.code == sf::Keyboard::Escape) {
				window.close ();
			}
		}
		if (mouse.isButtonPressed (mouse.Left)) {
			std::cout << "BEFORE: "<< ptrLevel [0] << std::endl;
			roadBuilding (window, ptrLevel);
			
			std::cout << "AFTER: " << ptrLevel [0] << std::endl;
		}
		/*if (keyboard.isKeyPressed) {
			movement(background);
		}*/
		
		window.clear ();
		window.setView (view);
		window.draw (background);
		window.draw (map);
		window.draw (convex);
		window.display ();
	}
	return EXIT_SUCCESS;
}

//void Game::movement(sf::Sprite& background){
//	if (keyboard.isKeyPressed(keyboard.W)) {
//		//view.move (0.f, -5.f);
//		//background.move (0.f, -5.f);
//		map.move (0.f, 5.f);
//	}
//	if (keyboard.isKeyPressed(keyboard.A)) {
//		//view.move (-5.f, 0.f);
//		//background.move (-5.f, 0.f);
//		map.move (5.f, 0.f);
//	}
//	if (keyboard.isKeyPressed(keyboard.S)) {
//		//view.move (0.f, 5.f);
//		//background.move (0.f, 5.f);
//		map.move (0.f, -5.f);
//	}
//	if (keyboard.isKeyPressed(keyboard.D)) {
//		//view.move (5.f, 0.f);
//		//background.move (5.f, 0.f);
//		map.move (-5.f, 0.f);
//	}
//}

void Game::ui (Economics economics) {

}

void Game::roadBuilding (sf::RenderWindow &window, int *Level) {
	if (mouse.isButtonPressed (mouse.Left)) {
		int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
		int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
		if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
			int toChange = xTile + yTile * 25;
			int toChangeUp = toChange - 25;
			int toChangeDown = toChange + 25;
			int toChangeLeft = toChange - 1;
			int toChangeRight = toChange + 1;
			int tileValue = 1;

			bool haveUp = false;	
			bool haveDown = false;
			bool haveRight = false;
			bool haveLeft = false;

			if (Level [toChangeRight] != 0 && Level [toChangeRight] != 4 && Level [toChangeRight] != 5 && Level [toChangeRight] != 7 && Level [toChangeRight] != 11) {	//1,2,3,6,8,9,10 => !=0,4,5,7,11
				haveRight = true;
				std::cout << haveRight << std::endl;
			}
			if (Level [toChangeLeft] != 0 && Level [toChangeLeft] != 2 && Level [toChangeLeft] != 3 && Level [toChangeLeft] != 9 && Level [toChangeLeft] != 11) {			//1,4,5,6,7,8,10 => !=2,3,9,11
				haveLeft = true;
				std::cout << haveLeft << std::endl;
			}  
			if (Level [toChangeUp] != 1 && Level [toChangeUp] != 3 && Level [toChangeUp] != 4 && Level [toChangeUp] != 11) {											//0,2,5,6,7,9,10 => != 1,3,4,11
				haveUp = true;
				std::cout << haveUp << std::endl;
			} 
			if (Level [toChangeDown] != 1 && Level [toChangeDown] != 2 && Level [toChangeDown] != 5 && Level [toChangeDown] != 6 && Level [toChangeDown] != 11) {		//0,3,4,7,8,9,10 => != 1,2,5,6,11
				haveDown = true;
				std::cout << haveDown << std::endl;
			} 
			
			//0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
			if (haveUp && haveDown && haveRight && haveLeft) {
				tileValue = 10;
				std::cout << "haveUp && haveDown && haveRight && haveLeft" << std::endl;
			} else if(haveUp && haveDown && haveRight && !haveLeft) {
				std::cout << "haveUp && haveDown && haveRight && !haveLeft" << std::endl;
				tileValue = 7;
			} else if (haveUp && haveDown && !haveRight && haveLeft) {
				tileValue = 9;
				std::cout << "haveUp && haveDown && !haveRight && haveLeft" << std::endl;
			} else if (haveUp && haveDown && !haveRight && !haveLeft) {
				tileValue = 0;
				std::cout << "haveUp && haveDown && !haveRight && !haveLeft" << std::endl;
			} else if (haveUp && !haveDown && haveRight && haveLeft) {
				tileValue = 8;
				std::cout << "haveUp && !haveDown && haveRight && haveLeft" << std::endl;
			} else if (haveUp && !haveDown && haveRight && !haveLeft) {
				tileValue = 4;
				std::cout << "haveUp && !haveDown && haveRight && !haveLeft" << std::endl;
			} else if (haveUp && !haveDown && !haveRight && haveLeft) {
				tileValue = 3;
				std::cout << "haveUp && !haveDown && !haveRight && haveLeft" << std::endl;
			} else if (haveUp && !haveDown && !haveRight && !haveLeft) {
				tileValue = 0;
				std::cout << "haveUp && !haveDown && !haveRight && !haveLeft" << std::endl;
			} else if (!haveUp && haveDown && haveRight && haveLeft) {
				tileValue = 6;
				std::cout << "!haveUp && haveDown && haveRight && haveLeft" << std::endl;
			} else if (!haveUp && haveDown && haveRight && !haveLeft) {
				tileValue = 5;
				std::cout << "!haveUp && haveDown && haveRight && !haveLeft" << std::endl;
			} else if (!haveUp && haveDown && !haveRight && haveLeft) {
				tileValue = 2;
				std::cout << "!haveUp && haveDown && !haveRight && haveLeft" << std::endl;
			} else if (!haveUp && haveDown && !haveRight && !haveLeft) {
				tileValue = 0;
				std::cout << "!haveUp && haveDown && !haveRight && !haveLeft" << std::endl;
			} else if (!haveUp && !haveDown && haveRight && haveLeft) {
				tileValue = 1;
				std::cout << "!haveUp && !haveDown && haveRight && haveLeft" << std::endl;
			} else if (!haveUp && !haveDown && haveRight && !haveLeft) {
				tileValue = 1;
				std::cout << "!haveUp && !haveDown && haveRight && !haveLeft" << std::endl;
			} else if (!haveUp && !haveDown && !haveRight && haveLeft) {
				tileValue = 1;
				std::cout << "!haveUp && !haveDown && !haveRight && haveLeft" << std::endl;
			} else if (!haveUp && !haveDown && !haveRight && !haveLeft) {
				tileValue = 1;
				std::cout << "!haveUp && !haveDown && !haveRight && !haveLeft" << std::endl;
			}
			std::cout << Level[toChangeUp] << std::endl;
			if (Level [toChangeUp] == 1 || haveUp) {
				if (!haveLeft && !haveRight) {
					Level [toChangeUp] = 0;
					tileValue = 0;
				} else if(!haveLeft &&  haveRight) {
					Level [toChangeRight] = 0;
					tileValue = 4;
				} else if(haveLeft && !haveRight) {
					Level [toChangeLeft] = 0;
					tileValue = 3;
				} else if (haveLeft && haveRight) {
					if (haveDown) {
						tileValue = 10;
					} else if (Level [toChangeDown] == 1) {
						if (Level [toChangeUp] == 1) {
							Level [toChangeUp] == 0;
						}
						tileValue = 10;
						Level [toChangeDown] == 0;
					}
				}
			}

			Level [toChange] = tileValue;
			map.load ("media/tiles/roadTilesetTest2.png", sf::Vector2u (64, 64), Level, 25, 12);
			std::cout << "CHANGE: " << Level [toChange] << std::endl;
		}
	}
}