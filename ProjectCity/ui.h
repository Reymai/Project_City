#pragma once

#include <SFML/Graphics.hpp>
#include <string> 

#include "economics.h"
#include "building.h"

class UI : public sf::Drawable, public sf::Transformable{
private:
	std::string moneyTxt;
	std::string peopleTxt;
	sf::Font font;
	sf::Text moneyUItext;
	sf::Text moneyUIcount;
	sf::Text peopleUItext;
	sf::Text peopleUIcount;
	sf::Text helpHouseBuilding;
	sf::Text helpComercialBuilding;
	sf::Text helpRoadBuilding;
	sf::Text helpRemove;

public:
	UI ();
	void load ();
	void update (Economics economics, Building building, sf::RenderWindow &window);
	void draw (sf::RenderTarget &target, sf::RenderStates states) const;
	
};

