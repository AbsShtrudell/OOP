#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class Screen 
{
public:
	Screen() {}
	~Screen() {}

	virtual void display() = 0;
};

class Dial : public Screen {
public:
	Dial() {}
	~Dial() {}

	void display() {
		cout << "    #####    \n";
		cout << "  ##  |  ##  \n";
		cout << " #    |    # \n";
		cout << "#     |     #\n";
		cout << " #     \\   # \n";
		cout << "  ##    \\##  \n";
		cout << "    #####    \n";
	}
};

class Display : public Screen {
public:
	Display() {}
	~Display() {}

	void display() {
		cout << "############\n";
		cout << "# 12:00 AM #  \n";
		cout << "############ \n";
	}
};

