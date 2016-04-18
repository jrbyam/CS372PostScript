#ifndef Triangle_h
#define Triangle_h

#include "Shape.h"
#include "Polygon.h"

class Triangle : public Shape {
public:
    Triangle(double sideLength) {
        this->sideLength = sideLength;
    }

    string draw(int xCoord, int yCoord) {
        Polygon triangle(3, sideLength);
        return triangle.draw(xCoord, yCoord);
    }
private:
    double sideLength = 0.0;
};


#endif
