#include "game.h"
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
	//creating a camera
	sf::View view(sf::Vector2f(50.0f, 1080.0 / 2.5f), sf::Vector2f(1920.0f, 1080.0f));
	view.setSize(1920.0f, 1080.0f);
	//creating background 
	sf::Sprite background(background);
	//creating and loading map
	tmx::TileMap map("media/map.tmx");
	//registering keyboard pressing
	sf::Keyboard keyboard;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed || event.key.code == keyboard.Escape)
				window.close();
		}
		//set background always in (0 ; 0)
		background.setPosition(view.getCenter().x - window.getSize().x / 2, view.getCenter().y - window.getSize().y / 2);

		if (keyboard.isKeyPressed) {
			movement(keyboard, view);
		}

		window.clear();
		window.draw(background);
		window.setView(view);
		window.draw(map);
		window.display();
	}
	return EXIT_SUCCESS;
}

void Game::movement(sf::Keyboard& keyboard, sf::View& view){
	if (keyboard.isKeyPressed(keyboard.W)) {
		std::cout << "Moving Up" << std::endl;
		view.move(0.0f, -1.5f);
	}
	if (keyboard.isKeyPressed(keyboard.A)) {
		std::cout << "Moving Left" << std::endl;
		view.move(-1.5f, 0.0f);
	}
	if (keyboard.isKeyPressed(keyboard.S)) {
		std::cout << "Moving Down" << std::endl;
		view.move(0.0f, 1.5f);
	}
	if (keyboard.isKeyPressed(keyboard.D)) {
		std::cout << "Moving Right" << std::endl;
		view.move(1.5f, 0.0f);
	}
	/*switch (event.type == event.KeyPressed) {
			case keyboard.W: {
				std::cout << "Moving Up" << std::endl;
				view.move(0.0f, -1.0f);
				break;
			}
			case keyboard.A: {
				std::cout << "Moving Left" << std::endl;
				view.move(-1.0f, 0.0f);
				break;
			}
			case keyboard.S: {
				std::cout << "Moving Down" << std::endl;
				view.move(0.0f, 1.0f);
				break;
			}
			case keyboard.D: {
					std::cout << "Moving Right" << std::endl;
					view.move(1.0f, 0.0f);
					break;
				}
			default:
				break;
		}*/
}
