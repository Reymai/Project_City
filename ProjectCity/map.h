#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "tile.h"

class Map : public sf::Drawable {
private:
	sf::Texture *tileset;
	sf::VertexArray *vertexArray;

	int width;
	int height;
	float tileTextureDimension;
	float tileWorldDimension;

	void AddTileVertices (Tile tile, sf::Vector2f position);

public:
	Map (sf::Texture tileset, int width, int height, float tileTextureDimension, float tileWorldDimension);

	virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

	virtual ~Map () {
	}
};