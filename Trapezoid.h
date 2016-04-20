#ifndef Trapezoid_h
#define Trapezoid_h

#include "Shape.h"

class Trapezoid : public Shape {
public:
    Trapezoid(double bottomLength, double topLength, double height) {
        this->bottomLength = bottomLength;
        this->topLength = topLength;
        this->height = height;

        boundW = bottomLength;
        boundH = height;
    }

    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        result += to_string(-bottomLength / 2) + " " + to_string(-height / 2) + " moveto\n"
                        + to_string(bottomLength) + " 0 rlineto\n" 
                        + to_string(-topLength / 4) + " " + to_string(height) + " rlineto\n"
			+ to_string(-topLength) + " 0 rlineto\n" 
                        + "closepath\n" + "stroke\ngrestore\n";
        return result;

    }
private:
    double bottomLength = 0.0;
    double topLength = 0.0;
    double height = 0.0;
};

#endif
