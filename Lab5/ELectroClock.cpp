#include "ELectroClock.h"

using namespace std;

void ELectroClock::save(std::string path)
{
	ofstream f(path, ios_base::app);
	if (getFormat() == Clock::Format::H24)
		f << "\ntime: " << getHour() << ":" << getMinute() << "\npower: " << pow.getPower();
	else
		f << "\ntime: " << (getHour() > 12 ? getHour() % 12 : getHour()) << ":" << getMinute() << (getHour() > 12 ? "PM" : "AM") << "\npower: " << pow.getPower();
}
