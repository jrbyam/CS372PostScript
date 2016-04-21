// Example.cpp
// Testing our custom Postscript library

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Square.h"
#include "Triangle.h"
#include "Layered.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Smiley.h"
#include "Trapezoid.h"
#include "Spacer.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
        // Circle of radius 72
        Circle firstThing(72);
	
        // Circle of radius 72, scaled by 2 in X and rotated 90 degrees
        Circle newThing(72);
        newThing.scale(2, 1);
        newThing.rotate(90);

        // Rectangle of width 100, height 200; scaled by 2 and rotated -90 degrees
	Rectangle secondThing(100, 200);
	secondThing.rotate(-90);
        secondThing.scale(2, 2);

        // Octagon with side length 50, scale by 3 in X and 5 in Y; rotated by 180
        Polygon thirdThing(8, 50);
        thirdThing.scale(3, 5);
        thirdThing.rotate(180);

        // Square with side length 75
        Square fourthThing(75);
        
        // Triangle with side length 200
        Triangle fifth(200);
        
        // Layered made of all previous shapes (except ellipse), scaled to half and rotated 90 degrees
        Layered sixth {&newThing, &secondThing, &thirdThing, &fourthThing, &fifth};
        sixth.scale(.5, .5);
        sixth.rotate(90);
        
        // Vertical made of elipse, rectangle and octagon, scaled in half and rotated 1080 degrees
        Vertical seventh({&newThing, &secondThing, &thirdThing});
        seventh.scale(.5, .5);
        seventh.rotate(1080);
        
        // Horizontal made of elipse and circle, scaled in half and rotated -90
        Horizontal eighth({&newThing, &firstThing});
        eighth.scale(.5, .5);
        eighth.rotate(-90);

        // Horizontal made of the previous Vertical and Horizontal
        Horizontal ninth({&seventh, &eighth});

        // Smiley of radius 50, rotated 180 degrees
        Smiley eleventh(50);
        eleventh.rotate(180);
        eleventh.scale(100, 100);
        
        // Trapezoid with bottom length 75, top length 50 and height 50
        Trapezoid thirteenth(75, 50, 50);
        thirteenth.rotate(180);
        
        Spacer spacer(50, 50);
        Horizontal fourteenth { &newThing, &spacer, &fourthThing  };
        cout << newThing.draw(300, 300);
        cout << "showpage\n" << endl;
        cout << sixth.draw(300, 300);
        cout << "showpage\n" << endl;
        cout << ninth.draw(300, 300);
        cout << "showpage\n";
        cout << thirteenth.draw(300, 300);
        cout << "showpage\n" << endl;
        cout << eleventh.draw(300, 300);
        cout << "showpage\n" << endl;
        cout << fourteenth.draw(300, 300) << endl;
        return 0;
};
