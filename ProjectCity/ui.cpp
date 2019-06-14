#include "ui.h"
#include <iostream>

UI::UI () {
}

void UI::load () {
	font.loadFromFile ("media/font.ttf");
}

void UI::update (Economics economics, sf::RenderWindow &window) {
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

	sf::Text helpHouseBuilding ("To build House press MIDDLE mouse button (WHEEL) | PRICE: )", font, 25);
	sf::Text helpComercialBuilding ("To build Market press LEFT mouse button | PRICE: 500", font, 25);
	sf::Text helpRoadBuilding ("To build Road press RIGHT mouse button | PRICE: 100", font, 25);

	helpHouseBuilding.Bold;
	helpHouseBuilding.setOutlineThickness (2.5);
	helpHouseBuilding.setPosition (5, window.getSize().y - 100);

	helpComercialBuilding.Bold;
	helpComercialBuilding.setOutlineThickness (2.5);
	helpComercialBuilding.setPosition (5, window.getSize ().y - 75);

	helpRoadBuilding.Bold;
	helpRoadBuilding.setOutlineThickness (2.5);
	helpRoadBuilding.setPosition (5, window.getSize ().y - 50);

	this->helpHouseBuilding = helpHouseBuilding;
	this->helpComercialBuilding = helpComercialBuilding;
	this->helpRoadBuilding = helpRoadBuilding;
}

void UI::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform ();

	target.draw (moneyUItext, states);
	target.draw (moneyUIcount, states);

	target.draw (helpHouseBuilding, states);
	target.draw (helpComercialBuilding, states);
	target.draw (helpRoadBuilding, states);


	
}
 