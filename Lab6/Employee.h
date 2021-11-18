#pragma once
#include "Human.h"
class Employee : public Human
{
protected:
	double salary;
	double* fines;
	int number;
public:
	Employee(string _name, int year, double _salary, int _number, double* _fines) : Human(_name, year)
	{
		salary = _salary;
		number = _number;
		fines = _fines;
	}
	Employee() { fines = nullptr; }
	void SetInformation()
	{
		Human::SetInformation();
		cout << "Salary: ", cin >> salary;
		cout << "Number of fines: ", cin >> number;
		fines = new double[number];
		for (int i = 0; i < number; i++)cin >> fines[i];
	}

	void GetInformation()
	{
		Human::GetInformation();
		cout << "Salary: " << salary << "\nFines:" << endl;
		for (int i = 0; i < number; i++)cout << fines[i] << " ";
		cout << endl;
	}

	void ChangeInformation(int point)
	{
		if (point < 3)
		{
			Human::ChangeInformation(point);
		}
		else
		{
			switch (point)
			{
			case 3: cout << "New salary: ", cin >> salary, cout << endl; break;
			case 4:
			{
				cout << "Number of fines: ", cin >> number, cout << endl;
				fines = new double[number];
				for (int i = 0; i < number; i++)cin >> fines[i];
				break;
			}
			default: cout << "Something wrong!" << endl;
			}

		}
	}
	~Employee()
	{
		if (fines != nullptr)delete fines;
	}
};


