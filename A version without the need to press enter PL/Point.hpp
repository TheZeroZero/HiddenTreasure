#include <iostream>

class Point
{
public:
	void setX(int newX);
	void setY(int newY);
	int getX() const { return x; }
	int getY() const { return y; }
// 	void setX_setY(int initialX, initialY);
private:
	//add a "char texture = [TEXTURE_HERE];" maybe? and make it be selected when making a new point:
	//Example: " Point example([TEXTURE_HERE]); "
	int x;
	int y;
};

void Point::setX(int newX)
{
	x = newX;
}

void Point::setY(int newY)
{
	y = newY;
}

// void Point::setX_setY(int initialX, initialY);
// {
// 	setX(initialX);
// 	setY(initialY);
// }