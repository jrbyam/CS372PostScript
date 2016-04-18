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
        for (auto shape : shapes) {
            children.push_back(shape);
        }     
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
