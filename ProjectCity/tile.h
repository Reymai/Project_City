#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile {
private:
	//position in the tileset
	int x;
	int y;

	sf::Color color;
public:

	Tile (int x, int y, sf::Color color);

	void setPosition (int x, int y);
	int getX ();
	int getY ();
	
};