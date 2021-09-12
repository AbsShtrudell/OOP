#pragma once
#include "Vector2d.h"
#include <string>
#include <fstream>

class Figure
{
public:
	Figure();
	Figure(int size, Vector2d);
	Figure(int size, int x, int y);
	~Figure();

	void Save(std::string path);

	int GetSize();
	Vector2d GetLocation();

	void SetSize(int size);
	void SetLocation(Vector2d location);
	void SetLocation(int x, int y);

	void Move(Vector2d step);
	void Move(int x, int y);

private:
	int size;
	Vector2d location;
};
