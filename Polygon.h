#ifndef Polygon_h
#define Polygon_h

#include "Shape.h"
#include <math.h>
#define PI 3.14
class Polygon : public Shape {
public:
    Polygon(int sides, double sideLength) {
        this->sides = sides;
        this->sideLength = sideLength;
    }

    string draw(int xCoord, int yCoord) {
        string result = "";

        for (int i = 0; i < sides; ++i) {
            double x = ((sideLength / 2) * ((sin(((2 * i + 1) * PI) / sides)) / (sin(PI / sides)))) + xCoord;
            double y = ((-sideLength / 2) * ((cos(((2 * i + 1) * PI) / sides)) / (sin(PI / sides)))) + yCoord;
            if (i == 0) {
                result += to_string(x) + " " + to_string(y) + " moveto\n";
            } else {
                result += to_string(x) + " " + to_string(y) + " lineto\n";
            }
        }
        return result + "closepath\nstroke\n";
    }
private:
    double sides = 0.0;
    double sideLength = 0.0;
};




#endif
