#pragma once
#include "Clock.h"
#include "PowerSource.h"
#include "Screen.h"

class MechClock : public Clock
{
public:
	Spring pow;
	Dial scr;

	void save(std::string path);
};
