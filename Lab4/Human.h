#pragma once
#include <cstringt.h>
#include <vector>

class Human
{
private:
	char Name[10];
	char Surename[10];
	int yearBirth;
	static std::vector<Human*> AllHumans;
public:
	Human();
	~Human();

	char* getName();
	void setName(char*);
	char* getSurename();
	void setSurename(char*);
	int getYearBirth();
	void setYearBirth(int);

	virtual void AddHuman();
	virtual void RemoveHuman();
	virtual void writeToFile(char* path) = 0;
};

