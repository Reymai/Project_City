#include "economics.h"
#include <iostream>

Economics::Economics (float money, int *Level) {
	setMoney (money);
	ptrLevel = Level;
}

void Economics::setMoney (float money) {
	this->money = money;
}

void Economics::costs (float cost) {
	money -= cost;
	this->money = money;
}

void Economics::incoming (float income) {
	this->money = money + income;
}

double Economics::getMoney () {
	return money;
}

void Economics::update () {
	for (int i = 0; i < 300; i++) {
		if (ptrLevel [i] == 2){
			this->money = money - 0.0001;
		}
		if (ptrLevel [i] == 1) {
			this->money = money + 0.01f;
		}
		if (ptrLevel [i] == 3) {
			this->money = money + 0.0001f;
		}
		if (ptrLevel [i] == 4) {
			this->money = money + 0.001f;
		}
		if (ptrLevel [i] == 5) {
			this->money = money + 0.01f;
		}
	}
}
