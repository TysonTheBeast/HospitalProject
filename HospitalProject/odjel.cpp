#include "odjel.h"
#include "krevet.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

int odjel::maxBrKreveta = 0;

void odjel::setMaxBrKreveta()
{
	cout << "Unesite max. broj kreveta na odjelu: ";
	cin >> odjel::maxBrKreveta;
	cin.ignore();
}

int odjel::getMaxBrKreveta()
{
	return odjel::maxBrKreveta;
}

void odjel::setNaziv()
{
	cout << "Unesite naziv odjela: ";
	cin.getline(this->naziv, 50);
}

void odjel::setKreveti()
{
	shared_ptr<krevet> temp = make_shared<krevet>();
	//krevet k;
	for (int i = 0; i < odjel::maxBrKreveta; i++)
	{
		/*k.setBroj(i);
		k.setStatus(slobodno);
		kreveti.push_back(k);*/
		temp->postaviKrevet(i, slobodno);
		this->kreveti.push_back(*temp);
	}
}

char* odjel::getNaziv()
{
	return this->naziv;
}

vector<krevet> odjel::getKreveti()
{
	return this->kreveti;
}

void odjel::postaviOdjel()
{
	this->setNaziv();
	this->setMaxBrKreveta();
	this->setKreveti();
}

void odjel::smjestiPacijenta()
{
	try
	{
		bool check = false;
		for (int i = 0; i < odjel::maxBrKreveta; i++)
		{
			if (kreveti[i].getStatus() == slobodno)
			{
				check = true;
				kreveti[i].setStatus(zauzeto);
				cout << "Pacijent uspjesno smjesten!" << endl;
				break;
			}
		}
		if (check == false)
		{
			throw "Svi kreveti su zauzeti";
		}
	}
	catch (const char* error)
	{
		cout << "[ERROR]" << error << endl;
	}
}

void odjel::rezKrevet()
{
	try
	{
		bool check = false;
		for (int i = 0; i < kreveti.size(); i++)
		{
			if (kreveti[i].getStatus() == slobodno)
			{
				check = true;
				kreveti[i].setStatus(rezervisano);
				cout << "Krevet rezervisan!" << endl;
				break;
			}
		}
		if (check == false)
		{
			throw "Svi kreveti su zauzeti";
		}
	}
	catch (const char* error)
	{
		cout << "[ERROR]" << error << endl;
	}
}

void odjel::oslobodiKrevet(int n)
{
	try
	{
		if (n < odjel::maxBrKreveta && n >= 0)
		{
			if (kreveti[n].getStatus() == zauzeto || kreveti[n].getStatus() == rezervisano)
			{
				kreveti[n].setStatus(slobodno);
			}
			else throw 1;
		}
		else throw 2;
	}
	catch (const int x)
	{
		if (x == 1)
		{
			cout << "Error: " << x << "| Taj krevet je vec slobodan." << endl;
		}
		else if (x == 2)
		{
			cout << "Error: " << x << "| Taj krevet ne postoji." << endl;
		}
	}
}

void odjel::ispisKreveta()
{
	cout << "Redni br. \nkreveta\t\t\tStatus kreveta" << endl;
	cout << "---------------------------------------" << endl;
	for (int i = 0; i < kreveti.size(); i++)
	{
		switch (kreveti[i].getStatus())
		{
		case 0:
		{
			cout << kreveti[i].getBroj() << "\t\t\t" << "slobodno" << endl;
			break;
		}
		case 1:
		{
			cout << kreveti[i].getBroj() << "\t\t\t" << "zauzeto" << endl;
			break;
		}
		case 2:
		{
			cout << kreveti[i].getBroj() << "\t\t\t" << "rezervisano" << endl;
			break;
		}
		}
	}
}

odjel::odjel()
{
	strcpy_s(this->naziv, "Novi odjel");
	this->maxBrKreveta = 0;
}

odjel::~odjel()
{
}
