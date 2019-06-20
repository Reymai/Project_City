#include "ui.h"
#include <iostream>

UI::UI () {
}

void UI::load () {
	font.loadFromFile ("media/font.ttf");
}

void UI::update (Economics economics, Building building, sf::RenderWindow &window) {
	int money;
	int people;
	
	money = economics.getMoney ();
	people = building.getPeopleCount ();

	if (people < 0) {
		people = 0;
	}

	moneyTxt = std::to_string (money);
	peopleTxt = std::to_string (people);

	//INFO
	sf::Text moneyUItext ("Money: ", font, 30);
	sf::Text moneyUIcount (moneyTxt, font, 30);

	sf::Text peopleUItext("People: ", font, 30);
	sf::Text peopleUIcount (peopleTxt, font, 30);

	moneyUItext.Bold;
	moneyUItext.setOutlineThickness (2.5);
	moneyUItext.setPosition (5, 5);
																					//Money: [Money count]
	moneyUIcount.Bold;
	moneyUIcount.setOutlineThickness (2.5);
	moneyUIcount.setPosition (moneyUItext.getPosition ().x + 150, moneyUItext.getPosition ().y);

	peopleUItext.Bold;
	peopleUItext.setOutlineThickness (2.5);
	peopleUItext.setPosition (moneyUItext.getPosition ().x, moneyUItext.getPosition ().y + 45);
																					//People: [People count]
	peopleUIcount.Bold;
	peopleUIcount.setOutlineThickness (2.5);
	peopleUIcount.setPosition (peopleUItext.getPosition ().x + 150, peopleUItext.getPosition ().y);

	if (money < 0) {
		moneyUItext.setFillColor (sf::Color::Red);
		moneyUIcount.setFillColor (sf::Color::Red);
	}

	this->moneyUItext = moneyUItext;
	this->moneyUIcount = moneyUIcount;
	this->peopleUItext = peopleUItext;
	this->peopleUIcount = peopleUIcount;

	//HELP

	sf::Text helpHouseBuilding ("To build House press MIDDLE mouse button (WHEEL)|PRICE: 250", font, 25);
	sf::Text helpComercialBuilding ("To build Market press LEFT mouse button  |PRICE: 500", font, 25);
	sf::Text helpRoadBuilding ("To build Road press RIGHT mouse button |PRICE: 100", font, 25);
	sf::Text helpRemove ("To remove any building press on keyboard Del(ete) button", font, 25);

	helpHouseBuilding.Bold;
	helpHouseBuilding.setOutlineThickness (2.5);
	helpHouseBuilding.setPosition (5, window.getSize().y - 125);

	helpComercialBuilding.Bold;
	helpComercialBuilding.setOutlineThickness (2.5);
	helpComercialBuilding.setPosition (5, window.getSize ().y - 100);

	helpRoadBuilding.Bold;
	helpRoadBuilding.setOutlineThickness (2.5);
	helpRoadBuilding.setPosition (5, window.getSize ().y - 75);

	helpRemove.Bold;
	helpRemove.setOutlineThickness (2.5);
	helpRemove.setPosition (5, window.getSize ().y - 50);

	this->helpHouseBuilding = helpHouseBuilding;
	this->helpComercialBuilding = helpComercialBuilding;
	this->helpRoadBuilding = helpRoadBuilding;
	this->helpRemove = helpRemove;
}

void UI::draw (sf::RenderTarget &target, sf::RenderStates states) const {
	states.transform *= getTransform ();

	target.draw (moneyUItext, states);
	target.draw (moneyUIcount, states);
	target.draw (peopleUItext, states);
	target.draw (peopleUIcount, states);

	target.draw (helpHouseBuilding, states);
	target.draw (helpComercialBuilding, states);
	target.draw (helpRoadBuilding, states);
	target.draw (helpRemove, states);


	
}
 