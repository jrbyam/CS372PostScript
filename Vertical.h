#ifndef Vertical_h
#define Vertical_h

#include "Shape.h"
#include <vector>
using std::vector;
#include <initializer_list>
using std::initializer_list;

class Vertical : public Shape {
public:
    Vertical(initializer_list<Shape *> shapes) {
        double largestBoundW = 0;
        for (auto shape : shapes) {
            children.push_back(shape);
            
            if (shape->boundW > largestBoundW) largestBoundW = shape->boundW;
            boundH += shape->boundH;
        }     
        boundW = largestBoundW;
    }
    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        double topBound = (boundH / 2) * (1 / scaleY);
        for (auto child : children) {
            result += child->draw(0, topBound - (child->boundH / 2));
            topBound -= child->boundH;
        }
        return result + "grestore\n";
    }
private:
    vector<Shape *> children = {};
};




#endif
