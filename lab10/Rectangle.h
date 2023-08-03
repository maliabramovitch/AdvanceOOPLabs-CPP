#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"
#include <string>

class Rectangle : public Shape {
protected:
	std::string color;
	Rectangle(const std::string &col);
public:
	virtual ~Rectangle();
	static Rectangle * createInstance(const std::string &s);
	void draw();
};

#endif /* RECTANGLE_H_ */
