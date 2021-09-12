#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Vector2d.h"
#include <conio.h>
#include <iostream>

using namespace std;

void CheckCircleMethods();
void CheckTriangleMethods();
void CheckSquareMethods();
void CheckRectangleMethods();

int main()
{
	char input;
	void (*methods)() = CheckCircleMethods;
	bool exit = false;
	string figure_types[4] = { "circle", "triangle", "square", "rectangle" };
	int type = 0;
	while (exit != true)
	{
		cout << "1.check methods 2.exitn\n\n[E]change figure class: " << figure_types[type] << endl;
		input = _getch();
		switch (input)
		{
		case '1':
			methods();
			break;
		case '2':
			exit = true;
			break;
		case'E':case 'e':
			type = type == 3 ? 0 : type + 1;
			switch (type)
			{
			case 0:
				methods = CheckCircleMethods;
				break;
			case 1:
				methods = CheckTriangleMethods;
				break;
			case 2:
				methods = CheckSquareMethods;
				break;
			case 3:
				methods = CheckRectangleMethods;
				break;
			}
			break;
		}
		system("CLS");
	}
}

void CheckCircleMethods()
{
	char selection;
	int input;
	int input2;
	string path;
	Circle circle;
	while (true)
	{
		system("CLS");
		cout << "CIRCLE\n";
		cout << "1.getLocation 2.getRadius 3.getSize 4.setSize 5.setRadius 6.setLocation 7.move 8.save 9.back\n";
		selection = _getch();
		switch (selection)
		{
		case '1':
			cout << circle.GetLocation().GetX() << circle.GetLocation().GetY();
			break;
		case '2':
			cout << circle.GetRadius();
			break;
		case '3':
			cout << circle.GetSize();
			break;
		case '4':
			cin >> input;
			circle.SetSize(input);
			break;
		case '5':
			cin >> input;
			circle.SetRadius(input);
			break;
		case '6':
			cin >> input >> input2;
			circle.SetLocation(Vector2d(input, input2));
			break;
		case '7':
			cin >> input >> input2;
			circle.Move(input, input2);
			break;
		case '8':
			cin >> path;
			circle.Save(path);
			break;
		case '9':
			return;
		}
		_getch();
	}
}

void CheckTriangleMethods()
{
	char selection;
	int input;
	int input2;
	string path;
	Triangle triangle;
	while (true)
	{
		system("CLS");
		cout << "TRIANGLE\n";
		cout << "1.getLocation 2.getSize 3.setSize 4.setLocation 5.move 6.save 7.back\n";
		selection = _getch();
		switch (selection)
		{
		case '1':
			cout << triangle.GetLocation().GetX() << triangle.GetLocation().GetY();
			break;
		case '2':
			cout << triangle.GetSize();
			break;
		case '3':
			cin >> input;
			triangle.SetSize(input);
			break;
		case '4':
			cin >> input >> input2;
			triangle.SetLocation(Vector2d(input, input2));
			break;
		case '5':
			cin >> input >> input2;
			triangle.Move(input, input2);
			break;
		case '6':
			cin >> path;
			triangle.Save(path);
			break;
		case '7':
			return;
		}
		_getch();
	}
}

void CheckSquareMethods()
{
	char selection;
	int input;
	int input2;
	string path;
	Square square;
	while (true)
	{
		system("CLS");
		cout << "SQUARE\n";
		cout << "1.getLocation 2.getSize 3.setSize 4.setLocation 5.move 6.save 7.back\n";
		selection = _getch();
		switch (selection)
		{
		case '1':
			cout << square.GetLocation().GetX() << square.GetLocation().GetY();
			break;
		case '2':
			cout << square.GetSize();
			break;
		case '3':
			cin >> input;
			square.SetSize(input);
			break;
		case '4':
			cin >> input >> input2;
			square.SetLocation(Vector2d(input, input2));
			break;
		case '5':
			cin >> input >> input2;
			square.Move(input, input2);
			break;
		case '6':
			cin >> path;
			square.Save(path);
			break;
		case '7':
			return;
		}
		_getch();
	}
}

void CheckRectangleMethods()
{
	char selection;
	int input;
	int input2;
	string path;
	Rectangle rectangle;
	while (true)
	{
		system("CLS");
		cout << "RECTANGLE\n";
		cout << "1.getLocation 2.getSize 3.setSize 4.setLocation 5.move 6.save 7.back\n";
		selection = _getch();
		switch (selection)
		{
		case '1':
			cout << rectangle.GetLocation().GetX() << rectangle.GetLocation().GetY();
			break;
		case '2':
			cout << rectangle.GetSize();
			break;
		case '3':
			cin >> input;
			rectangle.SetSize(input);
			break;
		case '4':
			cin >> input >> input2;
			rectangle.SetLocation(Vector2d(input, input2));
			break;
		case '5':
			cin >> input >> input2;
			rectangle.Move(input, input2);
			break;
		case '6':
			cin >> path;
			rectangle.Save(path);
			break;
		case '7':
			return;
		}
		_getch();
	}
}
