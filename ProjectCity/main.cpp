#include "menu.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Project City", sf::Style::Close | sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	
	Menu menu;
	menu.load(window);
}