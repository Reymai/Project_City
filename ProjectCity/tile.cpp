#include "tile.h"

Tile::Tile (int x, int y, sf::Color color) {
	this->x = x;
	this->y = y;
	this->color = color;
}

void Tile::setPosition (int x, int y) {
	this->x = x;
	this->y = y;
}

int Tile::getX () {
	return x;
}

int Tile::getY () {
	return y;
}