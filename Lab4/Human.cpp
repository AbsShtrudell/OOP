#include "Human.h"

Human::Human()
{
	ZeroMemory(Name, 10);
	ZeroMemory(Surename, 10);
	yearBirth = 0;
}

Human::~Human()
{
}

char* Human::getName()
{
	return Name;
}

void Human::setName(char* _name)
{
	strcpy_s(Name,10, _name);
}

char* Human::getSurename()
{
	return Surename;
}

void Human::setSurename(char* _surename)
{
	strcpy_s(Surename, 10, _surename);
}

int Human::getYearBirth()
{
	return yearBirth;
}

void Human::setYearBirth(int year)
{
	yearBirth = year;
}