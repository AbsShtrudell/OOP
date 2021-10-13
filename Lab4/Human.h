#pragma once
#include <cstringt.h>
#include <vector>
#include "tinyxml2.h"

class Human
{
private:
	char Name[10];
	char Surename[10];
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

