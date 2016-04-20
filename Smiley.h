#ifndef Smiley_h
#define Smiley_h

#include "Shape.h"

class Smiley : public Shape {
public:
    Smiley(double radius) {
        this->radius = radius;
        boundW = 2 * radius;
        boundH = 2 * radius;
    }

    string draw(int xCoord, int yCoord) {
        string result = "gsave\n" + to_string(xCoord) + " " + to_string(yCoord) + " translate\n";

        // Handle rotation
        result += to_string(rotation) + " rotate\n";

        // Handle scale
        result += to_string(scaleX) + " " + to_string(scaleY) + " scale\n";

        result += "0 0 " + to_string(radius) + " 0 360 arc\n"; // Build a circle path
        result += "255 255 0 setrgbcolor fill\n"; // Fill it with yellow
        result += "0 0 0 setrgbcolor\n"; // Set color back to black
        result += "0 0 " + to_string(radius) + " 0 360 arc stroke\n"; // Make a border on the face
        result += to_string(boundW / 4) + " " + to_string(boundH / 4) + " " + to_string(radius / 7)
                  + " 0 360 arc fill\n"; // Right eye
        result += to_string(-boundW / 4) + " " + to_string(boundH / 4) + " " + to_string(radius / 7)
                  + " 0 360 arc fill\n"; // Left eye
        result += "1 0 0 setrgbcolor\n"; // Set color to red
        result += to_string(boundW / 5) + " " + to_string(-boundH / 4) + " " + to_string(radius / 7)
                  + " 205 50 arc fill\n"; // Tongue
        result += "0 0 0 setrgbcolor\n"; // Set color back to black
        result += to_string(3 * scaleX) + " setlinewidth\n"; // Thicken the line
        result += "0 0 " + to_string(radius * .6) + " 215 325 arc stroke\n"; // Make a smiling mouth
        return result + "grestore\n";
    }

    void scale(double scaleX, double scaleY) {} // Override to do nothing (not allow scaling)
private:
    double radius = 0.0;
};

#endif
