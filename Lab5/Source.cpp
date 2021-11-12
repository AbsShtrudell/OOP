#include "MechClock.h"
#include "ELectroClock.h"
#include "Clock.h"
#include <conio.h>

int main()
{
	char input;
	ELectroClock ec;
	MechClock mc;
	bool ismc = true;
	while (true) 
	{
		if (ismc) mc.scr.display();
		else ec.scr.display();
		std::cout << "1.change clocks\n2.get power\n3.charge\n4.show time\n5.change format\n6.save";
		if (_kbhit())
		{
			input = _getch();
			switch (input)
			{
			case'1':
				ismc = !ismc;
				break;
			case '2':
				if (ismc) cout << "power: " << mc.pow.getPower();
				else cout << "power: " << ec.pow.getPower();
				_getch();
				break;
			case '3': 
				if (ismc) mc.pow.charge();
				else ec.pow.charge();
				_getch();
				break;
			case'4':
				if (ismc) cout << endl << (mc.getHour() > 12 ? mc.getHour() % 12 : mc.getHour()) << ":" << mc.getMinute() << (mc.getHour() > 12 ? " PM" : " AM");
				else cout << endl << (ec.getHour() > 12 ? ec.getHour() % 12 : ec.getHour()) << ":" << ec.getMinute() << (ec.getHour() > 12 ? " PM" : " AM");
				_getch();
			case'5':
				if (ismc) mc.changeFormat();
				else ec.changeFormat();
				break;
			case'6':
				if (ismc) mc.save("test.txt");
				else ec.save("test.txt");
				cout << "\nsaved!";
				break;
			}
		}
		Sleep(200);
		ec.update();
		mc.update();
		system("CLS");
	}
}

void displayClock(ELectroClock cl) {
	cl.scr.display();
}

void displayClock(MechClock cl) {
	cl.scr.display();
}