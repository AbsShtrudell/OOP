#include <iostream>
#include <conio.h>
#include "Businessman.h"
#include "Traveller.h"
#include "Trader.h"

using namespace std;

void Clear();

int main()
{
	char input;
	bool exit = false;
	char buff[20];
	int n;

	Businessman* b = nullptr;
	Traveller* t = nullptr;
	Trader* tr = nullptr;
	while (!exit)
	{
		cout << "1.Add businessman\n2.Add traveller\n3.Add trader\n4.exit\n";

		input = _getch();
		switch (input)
		{
		case '1':
			b = new Businessman;
			cout << "Enter name: ";
			cin.getline(buff, 20);
			b->setName(buff);
			Clear();

			cout << "Enter surename: ";
			cin.getline(buff, 20);
			b->setSurename(buff);
			Clear();

			cout << "Enter birthday: ";
			cin >> n;
			b->setYearBirth(n);
			Clear();

			cout << "Enter regadress: ";
			cin.getline(buff, 20);
			b->setRegAdress(buff);
			Clear();

			cout << "Enter License: ";
			cin >> n;
			b->setLicense(n);
			Clear();

			while (true)
			{
				cout << "Do you want to add tax? [Y/N]\n";
				input = _getch();
				if (input == 'y' || input == 'Y')
				{
					cout << "Enter date: ";
					cin.getline(buff, 20);
					Clear();

					cout << "Enter amount: ";
					cin >> n;
					Clear();

					b->AddTax(buff, n);
				}
				else break;
			}
			b->writeToFile((char*)"persons.xml");
			delete b;
			break;
		case '2':
			t = new Traveller;
			cout << "Enter name: ";
			cin.getline(buff, 20);
			t->setName(buff);
			Clear();

			cout << "Enter surename: ";
			cin.getline(buff, 20);
			t->setSurename(buff);
			Clear();

			cout << "Enter birthday: ";
			cin >> n;
			t->setYearBirth(n);
			Clear();

			cout << "Enter passportID: ";
			cin >> n;
			t->setPassportID(n);
			Clear();

			while (true)
			{
				cout << "Do you want to add borderpass? [Y/N]\n";
				input = _getch();
				if (input == 'y' || input == 'Y')
				{
					cout << "Enter country: ";
					cin.getline(buff, 20);
					Clear();

					cout << "Enter date: ";
					cin >> n;
					Clear();

					t->addBorderData(buff, n);
				}
				else break;
			}
			t->writeToFile((char*)"persons.xml");
			delete t;
			break;
		case'3':
			tr = new Trader;
			cout << "Enter name: ";
			cin.getline(buff, 20);
			tr->setName(buff);
			Clear();

			cout << "Enter surename: ";
			cin.getline(buff, 20);
			tr->setSurename(buff);
			Clear();

			cout << "Enter birthday: ";
			cin >> n;
			tr->setYearBirth(n);
			Clear();

			while (true)
			{
				cout << "Do you want to add offer operation? [Y/N]\n";
				input = _getch();
				if (input == 'y' || input == 'Y')
				{
					cout << "Enter date: ";
					cin.getline(buff, 20);
					Clear();

					cout << "Enter amount: ";
					cin >> n;
																											
					Clear();

					tr->addOfferData(buff, n);
				}
				else break;
			}
			tr->writeToFile((char*)"persons.xml");
			delete tr;
			break;
		case '4':
			system("start persons.xml");
			exit = true;
			break;
		}
	}
	
}

void Clear()
{
	cin.clear();
	while (cin.get() != '\n');
}
