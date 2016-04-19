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
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";
        
        for (auto child : children) {
            result += child->draw(0, 0);
        }
        return result;
    }
private:
    vector<Shape *> children = {};
};

#endif
