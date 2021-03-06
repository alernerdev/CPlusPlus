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

public:
	// this constructor needs to be public in order for the Factory to get to it,
	// or the factory needs to be a friend of the class its constructing
	Point(float x, float y): x(x), y(y) {}

	friend ostream & operator<<(ostream &os, const Point & point)
	{
		os << "x: " << point.x << " y: " << point.y;
		return os;
	}
};

struct PointFactory
{
	static Point NewCartesian(float x, float y)
	{
		// the point constructor needs to be public
		return { x,y };
	}
	static Point NewPlolar(float r, float theta)
	{
		return { r*cos(theta), r*sin(theta) };
	}

};

int main()
{
	auto p = PointFactory::NewPlolar(20, M_PI_4);
	cout << p << endl;

	getchar();
	return 0;
}
