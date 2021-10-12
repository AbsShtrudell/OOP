#pragma once
#include "Human.h"
class Businessman : public Human
{
private:
	int License;
	char RegAdress[30];
	struct Taxes
	{
		char Date[20];
		float amount;
	};
	std::vector<Taxes> TaxData;
public:

	Businessman();
	~Businessman();

	int getLicense();
	void setLicense(int _license);
	char* getRegAdress();
	void setRegAdress(char* _regadress);


	void AddTax(char* _date, float _amount);
	std::vector<Taxes> getTaxData()
	{
		return TaxData;
	}

	virtual void writeToFile(char* path);

};

