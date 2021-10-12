#include <iostream>
#include "String.h"
#include <conio.h>

using namespace std;

int main()
{
	int n = 0;
	char input;
	bool exit = false;
	String* a = nullptr, *b = nullptr;
	int i;
	while (!exit)
	{
		cout << "1.Initialize first string\n2.Initilize second string\n3.Check methods\n4.exit\n";
		input = _getch();
		switch (input)
		{
		case '1':

			cout << "Enter first string length: \n";
			if (!(cin >> n))
			{
				cout << "wrong value\n";
				cin.clear();
				while (cin.get() != '\n');
				break;
			}
			if (n < 2)
			{
				cout << "wrong value\n";
				cin.clear();
				while (cin.get() != '\n');
				break;
			}
			if (a != NULL)
				delete a;
			a = new String(n);
			cout << "Enter first string: \n";
			cin >> *a;
			cout << *a << endl;
			cin.clear();
			while (cin.get() != '\n');
			break;
		case '2':
			cout << "Enter second string length: \n";
			if (!(cin >> n))
			{
				cout << "wrong value\n";
				cin.clear();
				while (cin.get() != '\n');
				break;
			}
			if (n < 2)
			{
				cout << "wrong value\n";
				cin.clear();
				while (cin.get() != '\n');
				break;
			}
			if (b != NULL)
				delete b;
			b = new String(n);
			cout << "Enter second string: \n";
			cin >> *b;
			cout << *b << endl;
			cin.clear();
			while (cin.get() != '\n');
			break;
		case '3':
			if (a != NULL && b != NULL)
			{
				cout << "a - b: " << *a - *b << endl;
				(*a)++;
				cout << "a++: " << *a << endl;
				i = *a > *b;
				cout << "a > b: " << i << endl;
			}
			else cout << "Initialize strings\n";
			break;
		case '4':
			exit = true;
			break;
		}
	}
}