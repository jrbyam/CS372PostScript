#ifndef Shape_h
#define Shape_h

#include <string>
using std::string;
using std::to_string;

class Shape {
public:
    virtual ~Shape() {}
    virtual string draw() = 0;
    virtual void rotate(int rotation) {
        this->rotation = rotation;
    }
    virtual void scale(double scaleX, double scaleY) {
        this->scaleX = scaleX;
        this->scaleY = scaleY;
    }

    int rotation = 0;
    double scaleX = 1.0;
    double scaleY = 1.0;
};

#endif
