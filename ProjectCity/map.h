#pragma once
#include <string>
#include <SFML/Graphics.hpp>

#include "tinyxml2.h"

class Map : public sf::Drawable, sf::Transformable{
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states);
	
public:
	Map(const std::string& filename);

	void update();
};

