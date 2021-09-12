#include "Vector2d.h"

Vector2d::Vector2d()
{
	this->x = 0;
	this->y = 0;
}

Vector2d::Vector2d(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2d::~Vector2d()
{

}

int Vector2d::GetX()
{
	return this->x;
}

int Vector2d::GetY()
{
	return this->y;
}

void Vector2d::SetX(int x)
{
	this->x = x;
}

void Vector2d::SetY(int y)
{
	this->y = y;
}

Vector2d Vector2d::operator-= (const Vector2d& vector)
{
	return Vector2d(this->x + vector.x, this->y + vector.y);
}

Vector2d Vector2d::operator+ (const Vector2d& vector)
{
	return Vector2d(this->x + vector.x, this->y + vector.y);
}

Vector2d Vector2d::operator- (const Vector2d& vector)
{
	return Vector2d(this->x + vector.x, this->y + vector.y);
}

Vector2d Vector2d::operator+= (const Vector2d& vector)
{
	return Vector2d(this->x + vector.x, this->y + vector.y);
}
