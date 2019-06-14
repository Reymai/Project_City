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
	sf::Sprite buildHouse;
	sf::Sprite buildComercial;
	sf::Text buildHouseText;
	sf::Text buildComercialText;

public:
	UI ();
	void load ();
	void update (Economics economics);
	void draw (sf::RenderTarget &target, sf::RenderStates states) const;
	
};

