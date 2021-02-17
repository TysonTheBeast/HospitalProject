#pragma once
#include <iostream>
#include "krevet.h"
#include <vector>

using std::vector;

class odjel
{
private:
	char naziv[50];
	vector<krevet> kreveti;
	static int maxBrKreveta;
public:
	static void setMaxBrKreveta();
	static int getMaxBrKreveta();
	void setNaziv();
	void setKreveti();
	char* getNaziv();
	vector<krevet> getKreveti();
	void postaviOdjel();
	void smjestiPacijenta();
	void rezKrevet();
	void oslobodiKrevet(int n);
	void ispisKreveta();
	odjel();
	~odjel();
};

