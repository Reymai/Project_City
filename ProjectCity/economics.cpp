#include "economics.h"
#include <iostream>

Economics::Economics (float money, int *Level) {
	setMoney (money);
	this->ptrLevel = Level;
}

void Economics::setMoney (float money) {
	this->money = money;
}

void Economics::paying (float cost) {
	money = money - cost;
}

double Economics::getMoney () {
	return money;
}


void Economics::update () {
	for (int i = 0; i < 300; i++) {
		if (ptrLevel [i] == 1) {
			money = money + 0.07f;
		}
		if (ptrLevel [i] == 2){
			money = money - 0.001;
		}
		if (ptrLevel [i] == 3) {
			money = money + 0.005f;
		}
		if (ptrLevel [i] == 4) {
			money = money + 0.003f;
		}
		if (ptrLevel [i] == 5) {
			money = money + 0.008f;
		}
	}
}
