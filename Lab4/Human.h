#pragma once
#include <cstringt.h>
#include <vector>
#include "tinyxml2.h"

class Human
{
private:
	char Name[20];
	char Surename[20];
	int yearBirth;
public:
	Human();
	~Human();

	char* getName();
	void setName(char*);
	char* getSurename();
	void setSurename(char*);
	int getYearBirth();
	void setYearBirth(int);

	virtual void writeToFile(char* path) = 0;
};

