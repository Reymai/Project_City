#include "building.h"


int Building::humansInHouses (int *Level, int type) {
	{
		srand (time (NULL));
		switch (type) {
		case 1:{
			people += 4;
			break;
		}
		case 2:{
			people += 6;
			break;
		}
		case 3:{
			people += 8;
			break;
		}
		case -1:{
			people -= 4;
			break;
		}
		case -2:{
			people -= 6;
			break;
		}
		case -3:{
			people -= 8;
			break;
		}
		default:
		break;
		}
	}
	return people;
}

Building::Building () {
	people = 0;
}

int Building::build (sf::RenderWindow &window, Economics economics, int *Level, Map map) {
	if (economics.getMoney () > -1500) {
		int xTile = (mouse.getPosition ().x - ((window.getSize ().x / 2) - 800)) / 64;
		int yTile = (mouse.getPosition ().y - ((window.getSize ().y / 2) - 384)) / 64;
		int toPay = 0;
		if (xTile < 25 && xTile >= 0 && yTile >= 0 && yTile < 12) {
			int toChange = xTile + yTile * 25;
			if (Level [toChange + 1] == 2 || Level [toChange - 1] == 2 || Level [toChange + 25] == 2 || Level [toChange - 25] == 2) {
				if (mouse.isButtonPressed (mouse.Left)) {
					if (Level [toChange] == 0) {
						Level [toChange] = 2;
						toPay += 50;
					}
				}
			}
			if (mouse.isButtonPressed (mouse.Right)) {
				if (Level [toChange + 1] == 2 || Level [toChange - 1] == 2 || Level [toChange + 25] == 2 || Level [toChange - 25] == 2) {
					if (Level [toChange] == 0) {
						Level [toChange] = 1;
						toPay += 250;
					}
				}
			}
			if (mouse.isButtonPressed (mouse.Middle)) {
				if (Level [toChange + 1] == 2 || Level [toChange - 1] == 2 || Level [toChange + 25] == 2 || Level [toChange - 25] == 2) {
					if (Level [toChange] == 0) {
						Level [toChange] = 3;
						people = humansInHouses (Level, 1);
						toPay += 100;
					}
				}
			}
			if (keyboard.isKeyPressed (keyboard.Delete)) {
				if (toChange == 5 * 25) {	//first element on 6 row
					return 0;
				}
				if (Level [toChange] == 1) {
					toPay -= 250;
				}
				if (Level [toChange] == 2) {
					toPay -= 50;
				}
				if (Level [toChange] == 3) {
					people = humansInHouses (Level, -1);
					toPay -= 100;
				}
				if (Level [toChange] == 4) {
					people = humansInHouses (Level, -2);
					toPay -= 350;
				}
				if (Level [toChange] == 5) {
					people = humansInHouses (Level, -3);
					toPay -= 650;
				}
				Level [toChange] = 0;

				int housesCount = 0;
				for (int i = 0; i < 300; i++) {
					if (Level [i] == 3 || Level [i] == 4 || Level [i] == 5) {
						housesCount++;
					}
				}
				if (housesCount = 0) {
					people = 0;
				}
			}
		}
		return toPay;
	} else {
		return 0;
	}
}

int Building::housesUpdate (int *Level, Economics economics, Map map) {
	int toPay = 0;
	for (int i = 0; i < 300; i++) {
		srand ((time (NULL)) + (rand () % 999));
		if (Level [i] == 3 && economics.getMoney () > 3000) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						srand ((time (NULL)) + (rand () % 99999999999));
						if (rand () % 2) {
							toPay += 100;
							Level [i] = 4;
							people = humansInHouses (Level, 2);
						}
					}
				}
			}
		}
		if (Level [i] == 4 && economics.getMoney () > 5000) {
			srand ((time (NULL)) + (rand () % 999));
			int j = 0;
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						srand ((time (NULL)) + (rand () % 99999999999));
						if (rand () % 2) {
							toPay += 300;
							people = humansInHouses (Level, 3);
							Level [i] = 5;
						}
					}
				}
			}
		}
		if (Level [i] == 4 && economics.getMoney () < 100) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						people = humansInHouses (Level, -3);
						Level [i] = 3;
					}
				}
			}
		}
		if (Level [i] == 5 && economics.getMoney () < 300) {
			if (rand () % 2) {
				srand ((time (NULL)) + (rand () % 99999999));
				if (rand () % 2) {
					srand ((time (NULL)) + (rand () % 999999999));
					if (rand () % 2) {
						people = humansInHouses (Level, -2);
						Level [i] = 4;
					}
				}
			}
		}
	}
	return toPay;
}

int Building::getPeopleCount () {
	return this->people;
}
