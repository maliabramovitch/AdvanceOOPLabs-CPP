#include "Circle.h"
#include "factory.h"
#include <iostream>

using namespace std;

registerInFactory<Shape, Circle> rc("circle");

Circle::Circle(const std::string &col) : color(col) { }

Circle::~Circle() { }

Circle * Circle::createInstance(const std::string &col)
{
	return new Circle(col);
}

void Circle::draw()
{
	cout << "This is a circle, color " << color << endl;
}
