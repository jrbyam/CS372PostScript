#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
	}
	string draw() {
		// Command is <x position> <y postion> <radius length> <starting angle> <ending angle> arc
		return ("0 0 moveto\n" + to_string(width) + " 0 lineto\n"
			+ to_string(width) + " " + to_string(height) + " lineto\n"
			+ "0 " + to_string(height) + " lineto\n" + "closepath\n" + "stroke\n");
	}
private:
	double width = 0;
	double height = 0;
};

#endif