#pragma once
#include <string>
#include <iostream>

using namespace std;

class Human
{
protected:
	string name;
	int yearOfBirth;
public:
	Human(string _name, int year) :
		name(_name), yearOfBirth(year) {}
	Human() {}
	void SetInformation()
	{
		cout << "Name: ", cin >> name;
		cout << "Year of birthday: ", cin >> yearOfBirth;
	}

	void GetInformation()
	{
		cout << "Name: " << name << "\nYear of birthday: " << yearOfBirth << endl;
	}

	void ChangeInformation(int point)
	{
		switch (point)
		{
		case 1: cout << "New name: ", cin >> name, cout << endl; break;
		case 2: cout << "New year of birthday: ", cin >> yearOfBirth, cout << endl; break;
		default: cout << "Something wrong!" << endl;
		}
	}
};

