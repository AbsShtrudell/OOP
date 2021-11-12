#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class PowerSource 
{
protected:
	float power;
public:
	PowerSource() {
		power = 100;
	}
	~PowerSource() {}

	virtual void charge() = 0;
	float getPower() {
		return power;
	}
};

class Battery : public PowerSource {
public:
	Battery() {}
	~Battery() {}

	void charge() {
		system("CLS");
		cout << "   ____\n  |    |]\n\n";
		Sleep(200);
		system("CLS");
		cout << "   ____\n  |#   |]\n\n";
		Sleep(200);
		system("CLS");
		cout << "   ____\n  |##  |]\n\n";
		Sleep(200);
		system("CLS");
		cout << "   ____\n  |### |]\n\n";
		Sleep(200);
		system("CLS");
		cout << "   ____\n  |####|]\n\n";
		cout << "charged!";
		power = 100;
	}
};

class Spring : public PowerSource {
public:
	Spring() {}
	~Spring() {}

	void charge() {
		system("CLS");
		cout << "  --\n  /\n  --\n  /\n  --\n  /\n  --\n";
		Sleep(200);
		system("CLS");
		cout << "\n  --\n  /\n  --\n  /\n  --\n  --\n";
		Sleep(200);
		system("CLS");
		cout << "\n\n  --\n  /\n  --\n  --\n  --\n";
		Sleep(200);
		system("CLS");
		cout << "\n\n\n  --\n  --\n  --\n  --\n\n";
		cout << "charged!";
		power = 100;
	}
};
