#pragma once
class Vector2d
{
public:
	Vector2d();
	Vector2d(int x, int y);
	~Vector2d();

	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);

	Vector2d operator+ (const Vector2d& vector);
	Vector2d operator- (const Vector2d& vector);
	Vector2d operator+= (const Vector2d& vector);
	Vector2d operator-= (const Vector2d& vector);

private:
	int x, y;
};
