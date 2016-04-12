#ifndef Circle_h
#define Circle_h

#include "Shape.h"

class Circle : public Shape {
    Circle(double radius) {
        this.radius = radius;
    }
    string draw() {
        return ("0 360 " + radius + " arc");
    }
private:
    double radius = 0;
};

#endif
