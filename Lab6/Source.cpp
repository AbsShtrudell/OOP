#include <windows.h>
#include <iostream>
#include "PayForm.h"

using namespace std;

int main() {
	PayForm payforms[10];
	int counter = 0;

	bool menu = true;
	int choose;
	while (menu)
	{
		cout << "1.Create payform\n2.See all payforms\n3.Edit payform\n4.Exit\n";
		while (!(cin >> choose))
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Wrong!" << endl;
		}

		switch (choose)
		{
		case 1: payforms[counter++].SetInformation(); break;
		case 2:
		{
			if (!counter)
			{
				cout << "Empty!" << endl;
				break;
			}

			for (int i = 0; i < counter; i++)
			{
				cout << i + 1 << ".\n";
				payforms[i].GetInformation();
			}
			break;
		}
		case 3:
		{
			if (!counter)
			{
				cout << "Empty!" << endl;
				break;
			}
			for (int i = 0; i < counter; i++)
			{
				cout << i + 1 << ".\n";
				payforms[i].GetInformation();
			}
			cout << "Which payform would you want to edit?\n";
			int number; cin >> number;
			payforms[number - 1].GetInformation();
			cout << "1.Name  2.Year  3.Salary  4.Fines  5.Percent" << endl;
			int point; cin >> point;
			payforms[number - 1].ChangeInformation(point);
			break;
		}
		case 4: menu = false; break;
		default: cout << "Something wrong!" << endl;
		}
	}

}
