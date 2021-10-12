#include "Businessman.h"

Businessman::Businessman()
{
	License = 0;
	ZeroMemory(RegAdress, 30);
}

Businessman::~Businessman()
{
}

int Businessman::getLicense()
{
	return License;
}

void Businessman::setLicense(int _license)
{
	if (_license < 1)
		License = 1;
	else License = _license;
}

char* Businessman::getRegAdress()
{
	return RegAdress;
}

void Businessman::setRegAdress(char* _regadress)
{
	strcpy_s(RegAdress, 30, _regadress);
}

void Businessman::AddTax(char* _date, float _amount)
{
	Taxes t;
	strcpy_s(t.Date, 20, _date);
	t.amount = _amount;
	TaxData.push_back(t);
}

void Businessman::writeToFile(char* path)
{
}

