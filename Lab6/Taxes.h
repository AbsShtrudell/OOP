#pragma once
#include <string>
#include <iostream>

using namespace std;

class Taxes
{
protected:
	double percent;
public:
	Taxes(double _percent)
	{
		percent = _percent;
	}
	Taxes(){}
	void SetInformation()
	{
		cout << "Percent: ", cin >> percent, cout << endl;
	}

	void GetInformation()
	{
		cout << "Percent: " << percent << endl;
	}

	void ChangeInformation()
	{
		cout << "New percent: ", cin >> percent, cout << endl;
	}
};

