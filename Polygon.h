#ifndef Polygon_h
#define Polygon_h

#include "Shape.h"
#include <math.h>
#define PI 3.14159265
class Polygon : public Shape {
public:
    Polygon(int sides, double sideLength) {
        this->sides = sides;
        this->sideLength = sideLength;
    }

    string draw(int xCoord, int yCoord) {
        double apothem = sideLength / (2 * tan(PI / sides));
        double angle = 180 * (sides - 2);
        string result = (to_string(xCoord - sideLength / 2) + " " 
                         + to_string(yCoord - apothem) + " moveto\n"
                         + to_string(sideLength) + " 0 rlineto\n"
                         + to_string(sideLength) + " 0 rmoveto\n");
        for (int i = 0; i < sides; ++i) {
            result += to_string(angle) + " rotate\n"
                      + to_string(sideLength) + " 0 rlineto\n"
                      + to_string(sideLength) + " 0 rmoveto\n";
        }
        return result + "stroke\n";
    }
private:
    int sides = 0;
    double sideLength = 0.0;
};




#endif
