#ifndef Shape_h
#define Shape_h

#include <string>
using std::string;
using std::to_string;

class Shape {
public:
    virtual ~Shape() {}
    virtual string draw(int xCoord, int yCoord) = 0;
    virtual void rotate(int rotation) {
        this->rotation = rotation;
        if (rotation % 180 != 0) {
            double temp = boundW;
            boundW = boundH;
            boundH = temp;
        }
    }
    virtual void scale(double scaleX, double scaleY) {
        this->scaleX = scaleX;
        this->scaleY = scaleY;
        boundW *= scaleX;
        boundH *= scaleY;
    }

    int rotation = 0;
    double scaleX = 1.0;
    double scaleY = 1.0;
    double boundW = 0.0;
    double boundH = 0.0;
};

#endif
