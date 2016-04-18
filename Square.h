#ifndef Square_h
#define Square_h

#include "Shape.h"
#include "Polygon.h"

class Square : public Shape {
public:
    Square(double sideLength) {
        this->sideLength = sideLength;
    }
    string draw(int xCoord, int yCoord) {
        Polygon square(4, sideLength);
        return square.draw(xCoord, yCoord);
    }
private:
    double sideLength = 0.0;
};


#endif
