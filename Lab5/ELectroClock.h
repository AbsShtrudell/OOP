#pragma once
#include "Clock.h"
#include "PowerSource.h"
#include "Screen.h"

class ELectroClock : public Clock  
{
public:
	Battery pow;
	Display scr;

	void save(std::string path);
};

