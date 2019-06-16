#include <iostream>

#include "menu.h"
#include "game.h"

int Menu::load(sf::RenderWindow& window) {
	// load background
	if (!background.loadFromFile("media/background.png"))
		return EXIT_FAILURE;
	//load menu buttons textures
	if (!button.loadFromFile("media/menu_button.png"))
		return EXIT_FAILURE;
	// load font
	if (!font.loadFromFile("media/font.ttf"))
		return EXIT_FAILURE;
	// load music
	if (!music.openFromFile("media/AMemoryAwayLong.ogg"))
		return EXIT_FAILURE;
	// load map

	Menu::draw(window);
}

int Menu::draw(sf::RenderWindow& window) {

	//creating background
	sf::Sprite background(background);
	//creating start button
	sf::Sprite start_button(button);
	//creating exit button
	sf::Sprite exit_button(button);
	//creating title text
	sf::Text title("Project City", font, 70);
	//creating start text
	sf::Text start_game_txt("Start", font, 45);
	//creating exit text
	sf::Text exit_game_txt("Exit", font, 45);
	
	sf::Mouse mouse;

	title.setPosition(window.getSize().x / 2.5, window.getSize().y / 1.5); //title position
	title.setOutlineThickness(2.5); //title outline thickness

	music.play();

	int opacity = 0; //Opacity
	int buttonOpacity = 0; //Opacity button

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			// Close window
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
				window.close();
		}
		//text movement
		while (title.getPosition().y > window.getSize().y / 2.5 - 50) {
			title.setPosition(title.getPosition().x, title.getPosition().y - 5);
			//text fadeIn
			if (opacity < 255) {  //text opacity
				opacity += 5;
				title.setOutlineColor(sf::Color(29, 184, 207, opacity));
				title.setFillColor(sf::Color(255, 255, 255, opacity));
			}
			window.clear();

			window.draw(background);
			window.draw(title);

			window.display();
		}

		//button fadeIn
		while (buttonOpacity < 255) { //button opacity
			buttonOpacity += 5;
			start_button.setColor(sf::Color(255, 255, 255, buttonOpacity));
			exit_button.setColor(sf::Color(255, 255, 255, buttonOpacity));

			start_button.setPosition(title.getPosition().x - 10, title.getPosition().y + 150);
			exit_button.setPosition(start_button.getPosition().x, start_button.getPosition().y + 150);

			start_game_txt.setPosition(start_button.getPosition().x + 150, start_button.getPosition().y + 10);
			exit_game_txt.setPosition(exit_button.getPosition().x + 160, exit_button.getPosition().y + 10);

			window.clear();

			window.draw(background);
			window.draw(title);
			window.draw(start_button);
			window.draw(exit_button);
			window.draw(start_game_txt);
			window.draw(exit_game_txt);

			window.display();
		}
		
		
		if (mouse.isButtonPressed(mouse.Left)) {	//if pressed left button
			bool MENU_CHOISE = Menu::buttons(start_button, exit_button);	
			switch (MENU_CHOISE) {
			case 0: {	//exit
				window.close();
				break;
			}
			case 1: {	//start
				window.clear();
				Game game;
				game.load(window);
				window.close();
				break;
			}
			default:
				break;
			}
		}

		window.clear();
		
		window.draw(background);
		window.draw(title);
		window.draw(start_button);
		window.draw(exit_button);
		window.draw(start_game_txt);
		window.draw(exit_game_txt);

		
		
		window.display();
	}
	return EXIT_SUCCESS;
}

int Menu::buttons(sf::Sprite &start_button, sf::Sprite &exit_button) {

	sf::Mouse mouse;
	sf::Mouse& Mouse = mouse;
	if (start_button.getGlobalBounds().contains(Mouse.getPosition().x, Mouse.getPosition().y)) {	//check if mouse is on start button
		std::cout << "start" << std::endl;
	}

	if (exit_button.getGlobalBounds().contains(Mouse.getPosition().x, Mouse.getPosition().y)) {		//check if mouse is on exit button
		return 0;
	} else {
		
	}
	return 1;
}