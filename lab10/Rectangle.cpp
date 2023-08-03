#include "Rectangle.h"
#include <iostream>
#include "factory.h"

using namespace std;


registerInFactory<Shape, Rectangle> rr("rect");


Rectangle::Rectangle(const string &col) : Shape(), color(col) { }

Rectangle::~Rectangle() { }

void Rectangle::draw()
{
	cout << "Rectangle n:" << i << " - color - " << color << endl;
}

Rectangle * Rectangle::createInstance(const string &s)
{
	return new Rectangle(s);
}
