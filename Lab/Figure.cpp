#include "Figure.h"

Figure::Figure()
{
	this->size = 1;
	this->location = Vector2d(0, 0);
}

Figure::Figure(int size, Vector2d)
{
	this->size = size;
	this->location = location;
}

Figure::Figure(int size, int x, int y)
{
	this->size = size;
	this->location = Vector2d(x, y);
}

Figure::~Figure()
{
}

void Figure::Save(std::string path)
{
	std::ofstream File;
	File.open(path, std::ios::app);
	File << "location: " << GetLocation().GetX() << " " << GetLocation().GetY() << std::endl;
	File << "size1: " << GetSize() << std::endl;
}

int Figure::GetSize()
{
	return this->size;
}

Vector2d Figure::GetLocation()
{
	return this->location;
}

void Figure::SetSize(int size)
{
	this->size = size;
}

void Figure::SetLocation(Vector2d location)
{
	this->location = location;
}

void Figure::SetLocation(int x, int y)
{
	this->location = Vector2d(x, y);
}

void Figure::Move(Vector2d step)
{
	location += step;
}

void Figure::Move(int x, int y)
{
	this->location += Vector2d(x, y);
}
