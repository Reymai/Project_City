#include "game.h"

int Game::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	tileset.loadFromFile ("media/road.png");
	Game::draw(window);
}

int Game::draw(sf::RenderWindow& window) {
	//creating background 
	sf::Sprite background(background);

	sf::View view;

	Map map(tileset, 10, 10, 70.f, 140.f);
	/*tmx::TileMap map("media/map.tmx");*/

	sf::Keyboard keyboard;

	/*map.ShowObjects();*/

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
		window.clear();
		window.draw(background);
		window.draw(map);
		window.display();
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