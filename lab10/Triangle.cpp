#include "Triangle.h"
#include <iostream>
#include "factory.h"
using namespace std;

registerInFactory<Shape, Triangle> tr1("triangle");
registerInFactory<Shape, Triangle> tr2("Triangle");

Triangle::Triangle(const string &col) : Shape(), color(col) { }

Triangle::~Triangle() { }

void Triangle::draw()
{
	cout << "Triangle n:" << i << " - color - " << color << endl;
}

Triangle * Triangle::createInstance(const string &s)
{
	return new Triangle(s);
}
