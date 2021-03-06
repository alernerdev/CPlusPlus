#include "pch.h"

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

enum class PointType
{
	cartesian, polar
};

class Point
{
private:
	float x, y;
	Point(float x, float y): x(x), y(y) {}

public:

	// this is called Factory Method implementation -- static methods which know how to create an object
	// Notice the constructor call is inferred from the uniform initialization list
	static Point NewCartesian(float x, float y)
	{
		return { x,y };
	}
	static Point NewPlolar(float r, float theta)
	{
		return { r*cos(theta), r*sin(theta) };
	}

	friend ostream & operator<<(ostream &os, const Point & point)
	{
		os << "x: " << point.x << " y: " << point.y;
		return os;
	}
};

int main()
{
	auto p = Point::NewPlolar(20, M_PI_4);
	cout << p << endl;

	getchar();
	return 0;
}
