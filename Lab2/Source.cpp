#include <conio.h>
#include <iomanip>
#include "Array.h"

ostream& table(ostream& stream);
template<typename T> void Print(Array<T> ar);

int main()
{
	int n;
	cout << "Enter array length ";
	if (!(cin >> n))
	{
		cout << "Value error";
		return 1;
	}
	Array<int> ar_int(n);
	Array<float> ar_fl(n);
	while (true)
	{
		cout << "Select array type\n1.int\n2.float\n3.exit\n\n";
		n = _getch();
		switch(n)
		{
		case'1':
			while (true)
			{
				cout << "1.enter array elements\n2.count sum\n3.show array elements\n4.exit\n\n";
				n = _getch();
				switch (n)
				{
				case'1':
					cout << "enter array elements : \n";
					for (int i = 0; i < ar_int.Length(); i++)
						if(!(cin >> ar_int[i]))
						{
							cout << "Value error";
							return 1;
						}	
					break;
				case '2':
					cout << "Enter number: ";
					if (!(cin >> n))
					{
						cout << "Value error";
						return 1;
					}
					cout << "Sum = " << ar_int.Count(n) << endl;
					break;
				case '3':
					cout << "Array elements\n";
					Print(ar_int);
					cout << endl;
					break;
				case '4':
					exit(0);
				}
			}
		case'2':
			while (true)
			{
				cout << "1.enter array elements\n2.count sum\n3.show array elements\n4.exit\n\n";
				n = _getch();
				switch (n)
				{
				case'1':
					cout << "enter array elements : \n";
					for (int i = 0; i < ar_fl.Length(); i++)
						if (!(cin >> ar_fl[i]))
						{
							cout << "Value error";
							return 1;
						}
					break;
				case '2':
					cout << "Enter number: ";
					if (!(cin >> n))
					{
						cout << "Value error";
						return 1;
					}
					cout << "Sum = " << ar_fl.Count(n) << endl;
					break;
				case '3':
					cout << "Array elements\n";
					Print(ar_fl);
					cout << endl;
					break;
				case '4':
					exit(0);
				}
			}
		case '3':
			exit(0);
		default:
			break;
		}
	}
}

template<typename T> void Print(Array<T> ar)
{
	
	for (int i = 0; i < ar.Length(); i++)
	{
		cout << "Array[" << i << "]" << table << ar[i] << endl;
	}
}

ostream& table(ostream& stream)
{
	stream << setw(5) << setfill('_');
	return stream;
}
