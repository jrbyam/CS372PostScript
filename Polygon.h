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

        if (sides % 2 != 0) {
            boundW = sideLength * ((sin((PI * (sides - 1) / (2 * sides)))) / (sin(PI / sides)));
            boundH = sideLength * ((1 + cos(PI / sides)) / (2 * sin(PI / sides)));
        } else {
            if (sides % 4 != 0) {
                boundW = sideLength * (1 / (sin(PI / sides)));
            } else {
                boundW = sideLength * ((cos(PI / sides)) / (sin(PI / sides)));
            }
            boundH = sideLength * ((cos(PI / sides)) / (sin(PI / sides)));
        }
    }

    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        for (int i = 0; i < sides; ++i) {
            double x = ((sideLength / 2) * ((sin(((2 * i + 1) * PI) / sides)) / (sin(PI / sides)))) + xCoord;
            double y = ((-sideLength / 2) * ((cos(((2 * i + 1) * PI) / sides)) / (sin(PI / sides)))) + yCoord;
            if (i == 0) {
                result += to_string(x) + " " + to_string(y) + " moveto\n";
            } else {
                result += to_string(x) + " " + to_string(y) + " lineto\n";
            }
        }
        return result + "closepath\nstroke\ngrestore\n";
    }
private:
    double sides = 0.0;
    double sideLength = 0.0;
};




#endif
