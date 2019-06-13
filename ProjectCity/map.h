#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


class Map : public sf::Drawable, public sf::Transformable {
private:
	virtual void draw (sf::RenderTarget &target, sf::RenderStates states) const;

	sf::VertexArray m_vertices;
	sf::Texture m_tileset;
public:
	bool load (const std::string &tileset, sf::Vector2u tileSize, const int *tiles, unsigned int width, unsigned int height);
};