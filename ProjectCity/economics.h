#pragma once
class Economics {
private:
	double money;
	int *ptrLevel;
public:
	Economics (double money, int *Level);
	
	void setMoney (int money);

	void costs (double cost);
	
	double getMoney ();

	void update ();
};

