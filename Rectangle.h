#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Circle : public Shape {
public:
	Circle(double radius) {
		this->radius = radius;
	}
	string draw() {
		// Command is <x position> <y postion> <radius length> <starting angle> <ending angle> arc
		return ("0 0 " + to_string(radius) + " 0 360 arc\n");
	}
private:
	double radius = 0;
};

#endif