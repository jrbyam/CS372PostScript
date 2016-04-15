#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(double radius) {
        this->radius = radius;
    }
    string draw(int xCoord, int yCoord) {
        // Command is <x position> <y postion> <radius length> <starting angle> <ending angle> arc
        return (to_string(xCoord) + " " + to_string(yCoord) + " " + to_string(radius) + " 0 360 arc stroke\n");
    }
private:
    double radius = 0;
};

#endif
