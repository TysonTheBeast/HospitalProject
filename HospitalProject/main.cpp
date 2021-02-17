#include "odjel.h"
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

int main()
{
	odjel o;
	o.postaviOdjel();
	system("pause");
	int x;
	do
	{
		do
		{
			system("cls");
			cout << "Odjel: " << o.getNaziv() << endl;
			cout << "[1] Ispis odjela" << endl;
			cout << "[2] Prijava pacijenta" << endl;
			cout << "[3] Rezervacija" << endl;
			cout << "[4] Oslobodi krevet" << endl;
			cout << "[5] Kraj" << endl;
			cout << "Izbor: ";
			cin >> x;
			cin.ignore();
			if (x == 1)
			{
				o.ispisKreveta();
				system("pause");
			}
			else if (x == 2)
			{
				o.smjestiPacijenta();
				system("pause");
			}
			else if (x == 3)
			{
				o.rezKrevet();
				system("pause");
			}
			else if (x == 4)
			{
				o.ispisKreveta();
				int x;
				cout << "Unesite krevet koji zelite da oslobodite: ";
				cin >> x;
				cin.ignore();
				o.oslobodiKrevet(x);
				system("pause");
			}
			else if (cin.fail())
			{
				cin.clear();
				cin.ignore();
			}
		} while (cin.fail());
	} while (x != 5);
	return 0;
}