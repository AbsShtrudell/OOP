#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>

class Clock
{
public:
	enum class Format { H12, H24 };

	Clock();
	Clock(int hour, int minute, Format format);
	Clock(const Clock& clock);
	~Clock();

	void setHour(int hour);
	int getHour() const;
	void setMinute(int minute);
	int getMinute() const;
	void setFormat(Format format);
	Format getFormat() const;
	void changeFormat();

	virtual void save(std::string path) = 0;
	void update();
private:

	int _hour;
	int _minute;
	Format _format;
};

