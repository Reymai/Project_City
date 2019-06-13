#pragma once
class Economics {
private:
	double money = 100;
	int *ptrLevel;
public:
	Economics (double money, int *Level);
	
	void setMoney (int money);
	
	double getMoney ();

	void update ();
};

