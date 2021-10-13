#include <iostream>
#include <conio.h>
#include "Businessman.h"
#include "Traveller.h"
#include "Trader.h"

using namespace std;

int main()
{
	char input;
	bool exit = false;
	char buff[20];
	int n;

	Businessman* b = nullptr;
	/*while (exit)
	{
		cout << "1.Initialize businessman\n2.Initializi traveller\n3.Initialize trader 4.Write them in to file\n5.exit\n";

		input = _getch();
		switch (input)
		{
		case '1':*/
			b = new Businessman;
			cout << "Enter name: ";
			cin.getline(buff, 20);
			b->setName(buff);
			cout << "Enter surename: ";
			cin.getline(buff, 20);
			b->setSurename(buff);
			cout << "Enter birthday: ";
			cin >> n;
			b->setYearBirth(n);
			cout << "Enter regadress: ";
			cin.getline(buff, 20);
			b->setRegAdress(buff);
			b->setLicense(456123);
			b->AddTax((char*)"20.10.2020", 156.54);
			b->AddTax((char*)"20.11.2020", 156.54);
			b->AddTax((char*)"20.12.2020", 156.54);
			b->writeToFile((char*)"persons.xml");
			Traveller t;
			t.addBorderData((char*)"poland", (char*)"20.09.2012");
			t.addBorderData((char*)"germany", (char*)"20.07.2015");
			t.writeToFile((char*)"persons.xml");
			Trader tr;
			tr.addOfferData((char*)"07.02.2010", 1024);
			tr.addOfferData((char*)"10.09.2012", 1024);
			tr.addOfferData((char*)"20.10.2012", 1024);
			tr.writeToFile((char*)"persons.xml");
			tr.writeToFile((char*)"person.xml");
	/*	}
	}*/
}