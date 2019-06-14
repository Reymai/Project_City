#pragma once
class Economics {
private:
	int *ptrLevel;
	float money;
public:
	Economics (float money, int *Level);
	
	void setMoney (float money);

	void costs (float cost);
	
	double getMoney ();

	void update ();
};

