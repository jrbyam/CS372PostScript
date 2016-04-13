#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape {
    Circle(double radius) {
        this.radius = radius;
    }
    string draw() {
        return ("0 " +   // x position
                "0 " +   // y postion
                radius + // Radius length
                " 0 " +  // Starting angle
                "360 " + // Ending angle
                " arc");
    }
private:
    double radius = 0;
};

#endif
