#include "ui.h"
#include <iostream>

UI::UI () {
}

void UI::load () {
	font.loadFromFile ("media/font.ttf");
}

void UI::update (Economics economics) {
	int money;
	money = economics.getMoney ();

	moneyTxt = std::to_string (money);

	sf::Text moneyUItext ("Money", font, 30);
	sf::Text moneyUIcount (moneyTxt, font, 30);

	moneyUItext.Bold;
	moneyUItext.setOutlineThickness (2.5);
	moneyUItext.setPosition (5, 5);
	
	moneyUIcount.Bold;
	moneyUIcount.setOutlineThickness (2.5);
	moneyUIcount.setPosition (moneyUItext.getPosition ().x + 150, moneyUItext.getPosition ().y);

	this->moneyUItext = moneyUItext;
	this->moneyUIcount = moneyUIcount;

}

void UI::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform ();
	// draw the vertex array
	target.draw (moneyUItext, states);
	target.draw (moneyUIcount, states);

	target.draw (buildComercial, states);
	target.draw (buildHouse, states);
	target.draw (buildHouseText, states);
	target.draw (buildComercialText, states);
	
}
 