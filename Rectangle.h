#ifndef Rectangle_h
#define Rectangle_h

#include "Shape.h"

class Rectangle : public Shape {
public:
	Rectangle(double width, double height) {
		this->width = width;
		this->height = height;
                boundW = width;
                boundH = height;
	}
	string draw(int xCoord, int yCoord) {
		string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

                // Handle rotation
                result += to_string(rotation) + " rotate\n";

                // Handle scale
                result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

		result += to_string(-width / 2) + " " + to_string(-height / 2) + " moveto\n" +
                          to_string(width) + " 0 rlineto\n 0 " + to_string(height) 
                        + " rlineto\n"
			+ to_string(-width) + " 0 rlineto\n" 
                        + "closepath\n" + "stroke\ngrestore\n";
                return result;
	}
private:
	double width = 0;
	double height = 0;
};

#endif
