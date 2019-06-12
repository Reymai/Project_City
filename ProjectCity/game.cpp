#include "game.h"

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	if(!tileset.loadFromFile ("media/test.png"))
		return EXIT_FAILURE;
	Game::draw(window);
}

int Game::draw(sf::RenderWindow& window) {
	//creating background 
	sf::Sprite background(background);

	sf::View view;

	const int level[] =
	{
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
	};

	Map map;
	if (!map.load ("media/road.png", sf::Vector2u (108, 70), level, 16, 8))
		return -1;
	/*tmx::TileMap map("media/map.tmx");*/

	sf::Keyboard keyboard;

	/*map.ShowObjects();*/

	sf::ConvexShape convex;

	convex.setPointCount (4);

	convex.setPoint (0, sf::Vector2f (0, 26));
	convex.setPoint (1, sf::Vector2f (52, 53.3f));
	convex.setPoint (2, sf::Vector2f (108.5f, 26));
	convex.setPoint (3, sf::Vector2f (52, 0));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		if (keyboard.isKeyPressed) {
			movement(keyboard, view);
		}
		window.clear ();
		window.draw (background);
		window.draw (map);
		window.draw (convex);
		window.display ();
	}
	return EXIT_SUCCESS;
}

void Game::movement(sf::Keyboard& keyboard, sf::View& view){
	if (keyboard.isKeyPressed(keyboard.W)) {
		view.move(0, 1.5f);
		std::cout << "Moving Up!" << std::endl;
	}
	if (keyboard.isKeyPressed(keyboard.A)) {
		view.move(1.5f, 0);
		std::cout << "Moving Left!" << std::endl;
	}
	if (keyboard.isKeyPressed(keyboard.S)) {
		view.move(0, -1.5f);
		std::cout << "Moving Down!" << std::endl;
	}
	if (keyboard.isKeyPressed(keyboard.D)) {
		view.move(-1.5f, 0);
		std::cout << "Moving Right!" << std::endl;
	}
}