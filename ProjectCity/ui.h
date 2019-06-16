#pragma once

#include <SFML/Graphics.hpp>
#include <string> 

#include "economics.h"

class UI : public sf::Drawable, public sf::Transformable{
private:
	std::string moneyTxt;
	sf::Font font;
	sf::Text moneyUItext;
	sf::Text moneyUIcount;
	sf::Text helpHouseBuilding;
	sf::Text helpComercialBuilding;
	sf::Text helpRoadBuilding;
	sf::Text helpRemove;

public:
	UI ();
	void load ();
	void update (Economics economics, sf::RenderWindow &window);
	void draw (sf::RenderTarget &target, sf::RenderStates states) const;
	
};

