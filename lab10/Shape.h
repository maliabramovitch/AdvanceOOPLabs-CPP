#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
	static int counter;
protected:
	int i;
	Shape();
public:
	virtual ~Shape();
	virtual void draw() = 0;
};

#endif /* SHAPE_H_ */
