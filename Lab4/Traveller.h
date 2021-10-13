#pragma once
#include "Human.h"
class Traveller : public Human
{
private:
	int passportID;
	struct Border
	{
		char country[20];
		char date[20];
	};
	std::vector<Border> borderData;
public:
	Traveller();
	~Traveller();

	int getPassportID();
	void setPassportID(int _passportId);
	void addBorderData(char* _country, char* _date);
	std::vector<Border> getBorderData()
	{
		return borderData;
	}

	virtual void writeToFile(char* path);
};

