#include "Circle.h"

Circle::Circle()
{
	this->radius = 1;
}

Circle::Circle(int size, Vector2d location, int radius)
{
	this->SetSize(size);
	this->SetLocation(location);
	this->radius = radius;
}

Circle::~Circle()
{
}

int Circle::GetRadius()
{
	return this->radius;
}

void Circle::SetRadius(int radius)
{
	this->radius = radius;
}

void Circle::Save(std::string path)
{
	std::ofstream File;
	File.open(path, std::ios::app);
	File << "location: " << GetLocation().GetX() << " " << GetLocation().GetY() << std::endl;
	File << "size: " << GetSize() << std::endl;
	File << "radius: " << GetRadius() << std::endl;
}
