#pragma once
#include <string>
#include <iostream>
#include "Employee.h"
#include "Taxes.h"

using namespace std;

class PayForm : public Employee, public Taxes
{
	double yearIncome;
	void CountYearIncome()
	{
		yearIncome = salary * 12 * (1 - percent / 100);
		for (int i = 0; i < number; i++)yearIncome -= fines[i];
	}
public:
	PayForm(string _name, int year, double _salary, int _number, double* _fines, double _percent = 0) :
		Employee(_name, year, _salary, _number, _fines),
		Taxes(_percent)
	{
		yearIncome = _salary * 12 * (1 - _percent / 100);
		for (int i = 0; i < _number; i++)yearIncome -= _fines[i];
	}
	PayForm() {}
	void SetInformation()
	{
		Employee::SetInformation();
		Taxes::SetInformation();
		CountYearIncome();
	}


	void GetInformation()
	{
		Employee::GetInformation();
		Taxes::GetInformation();
		cout << "Year income: " << yearIncome << endl;
	}

	void ChangeInformation(int point)
	{
		switch (point)
		{
		case 5:
		{
			Taxes::ChangeInformation();
			break;
		}
		default: Employee::ChangeInformation(point);
		}
		CountYearIncome();
	}

};

