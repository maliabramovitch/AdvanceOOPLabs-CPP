#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "factory.h"
using namespace std;

int main(void) {

  unique_ptr<Shape> s1 = genericFactory<Shape>::instance().create("triangle", "red");
  s1->draw();
  
  unique_ptr<Shape> s2 = genericFactory<Shape>::instance().create("rect", "blue");
  s2->draw();
  
  unique_ptr<Shape> s3 = genericFactory<Shape>::instance().create("circle", "orange");
  s3->draw();

  return 0;
}
