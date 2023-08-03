#include "Shape.h"

int Shape::counter = 0;

Shape::Shape() : i(counter++) { }

Shape::~Shape() { }

