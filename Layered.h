#ifndef Layered_h
#define Layered_h

#include "Shape.h"
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;

class Layered : public Shape {
public:
    Layered(initializer_list<Shape *> shapes) {
        double largestBoundW = 0;
        double largestBoundH = 0;
        for (auto shape : shapes) {
            children.push_back(shape);
            
            if (shape->boundW > largestBoundW) largestBoundW = shape->boundW;
            if (shape->boundH > largestBoundH) largestBoundH = shape->boundH;
        }
        boundH = largestBoundH;
        boundW = largestBoundW;     
    }
    string draw(int xCoord, int yCoord) {
        string result = "";
        for (auto child : children) {
            result += child->draw(xCoord, yCoord);
        }
        return result;
    }
private:
    vector<Shape *> children = {};
};

#endif
