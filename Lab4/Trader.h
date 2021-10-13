#pragma once
#include "Human.h"
class Trader : public Human
{
private:
	struct offer
	{
		char date[20];
		int offerID;
	};
	std::vector<offer> offerData;
public:
	Trader();
	~Trader();

	void addOfferData(char* _date, int _offerID);
	std::vector<offer> getOfferData()
	{
		return offerData;
	}

	virtual void writeToFile(char* path);
};

