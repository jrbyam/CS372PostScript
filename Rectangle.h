#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
	}
	string draw(int xCoord, int yCoord) {
		// Command is <x position> <y postion> <radius length> <starting angle> <ending angle> arc
		return (to_string(xCoord - width / 2) + " " + to_string(yCoord - height / 2) 
                        + " moveto\n" + to_string(width) + " 0 rlineto\n 0 " + to_string(height) 
                        + " rlineto\n"
			+ to_string(-width) + " 0 rlineto\n" 
                        + "closepath\n" + "stroke\n");
	}
private:
	double width = 0;
	double height = 0;
};

#endif
