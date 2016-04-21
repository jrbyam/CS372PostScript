#ifndef Spacer_h
#define Spacer_h

#include "Shape.h"

class Spacer : public Shape {
public:
    Spacer(double width, double height) {
        this->width = width;
        this->height = height;
        boundW = width;
        boundH = height;
    }

    string draw(int xCoord, int yCoord) {
        return "";
    }
private:
    double width = 0.0;
    double height = 0.0;
};

#endif
