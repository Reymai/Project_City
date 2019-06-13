#include "economics.h"

Economics::Economics (double money, int *Level) {
	setMoney (money);
	ptrLevel = Level;
}

void Economics::setMoney (int money) {
		this->money = money;
}

double Economics::getMoney () {
	return money;
}

void Economics::update () {
	for (int i = 0; i < 300; i++) {
		if (ptrLevel [i] == 12) {
			money++;
		}
	}
}
