#include "Human.h"

Human::Human()
{
	ZeroMemory(Name, 20);
	ZeroMemory(Surename, 20);
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
	strcpy_s(Name,20, _name);
}

char* Human::getSurename()
{
	return Surename;
}

void Human::setSurename(char* _surename)
{
	strcpy_s(Surename, 20, _surename);
}

int Human::getYearBirth()
{
	return yearBirth;
}

void Human::setYearBirth(int year)
{
	yearBirth = year;
}