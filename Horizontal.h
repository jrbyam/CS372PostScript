#ifndef Horizontal_h
#define Horizontal_h

#include "Shape.h"
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;

class Horizontal : public Shape {
public:
    Horizontal(initializer_list<Shape *> shapes) {
        double largestBoundH = 0;
        for (auto shape : shapes) {
            children.push_back(shape);
            
            if (shape->boundH > largestBoundH) largestBoundH = shape->boundH;
            boundW += shape->boundW;
        }     
        boundH = largestBoundH;
    }
    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        double leftBound = xCoord - (boundW / 2);
        for (auto child : children) {
            result += child->draw(leftBound + (child->boundW / 2), yCoord);
            leftBound += child->boundW;
        }
        return result + "grestore\n";
    }
private:
    vector<Shape *> children = {};
};




#endif
