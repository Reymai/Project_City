#include "economics.h"
#include <iostream>

Economics::Economics (double money, int *Level) {
	setMoney (money);
	ptrLevel = Level;
}

void Economics::setMoney (int money) {
	this->money = money;
}

void Economics::costs (double cost) {
	this->money = money - cost;
	std::cout << "HAS COST!"<< money  << std::endl;

}

double Economics::getMoney () {
	return money;
}

void Economics::update () {
	for (int i = 0; i < 300; i++) {
		if (ptrLevel [i] == 1) {
			this->money = money + 0.01f;
		}
	}
}
