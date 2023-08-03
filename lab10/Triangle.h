#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <string>
#include "Shape.h"

class Triangle : public Shape {
protected:
	std::string color;
	Triangle(const std::string &color);
public:
	virtual ~Triangle();
	static Triangle * createInstance(const std::string &color);
	void draw();
};

#endif /* TRIANGLE_H_ */
