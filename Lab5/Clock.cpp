#include "Clock.h"

Clock::Clock()
{
    _hour = 12;
    _minute = 0;
    _format = Clock::Format::H24;
}

Clock::Clock(int hour, int minute, Clock::Format format)
{
    setHour(_hour);
    setMinute(minute);
    setFormat(format);
}

Clock::Clock(const Clock& clock)
{
    _hour = clock._hour;
    _minute = clock._minute;
    _format = clock._format;
}

Clock::~Clock()
{
}

void Clock::setHour(int hour)
{
    if (_hour > 24) _hour = 24;
    else _hour = hour;
}

int Clock::getHour() const
{
    return _hour;
}

void Clock::setMinute(int minute)
{
    if (_minute > 60) _minute = 60;
    else _minute = minute;
}

int Clock::getMinute() const
{
    return _minute;
}

void Clock::setFormat(Format format)
{
    _format = format;
}

Clock::Format Clock::getFormat() const
{
    return Format();
}

void Clock::changeFormat()
{
    if (_format == Format::H24) _format = Format::H12;
    else _format = Format::H24;
}

void Clock::update()
{
    if (_minute == 60) {
        if (_hour == 24) _hour = 1;
        else _hour++;
        _minute = 1;
    }
    else _minute++;
}
