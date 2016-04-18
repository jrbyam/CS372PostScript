#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius) {
        this->radius = radius;
        boundW = 2 * radius;
        boundH = 2 * radius;
    }
    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        // Command is <x position> <y postion> <radius length> <starting angle> <ending angle> arc
        result += "0 0 " + to_string(radius) + " 0 360 arc stroke\ngrestore\n";

        return result;
    }
private:
    double radius = 0;
};

#endif
