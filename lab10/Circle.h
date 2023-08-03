#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <string>
#include "Shape.h"

class Circle: public Shape {
	std::string color;
public:
	Circle(const std::string &col);
	static Circle *createInstance(const std::string &col);
	virtual ~Circle();
	void draw();
};

#endif /* CIRCLE_H_ */
