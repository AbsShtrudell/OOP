#pragma once
#include "Figure.h"

class Circle : public Figure
{
public:
	Circle();
	Circle(int size, Vector2d, int radius);
	~Circle();

	int GetRadius();
	void SetRadius(int radius);

	void Save(std::string path);
private:
	int radius;
};
