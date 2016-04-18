// Example.cpp
// Testing our custom Postscript library

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Square.h"
#include "Triangle.h"
#include "Layered.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Circle newThing = Circle(72);
	Rectangle secondThing = Rectangle(100, 200);
	Polygon thirdThing(11, 50);
        Square fourthThing(75);
        Triangle fifth(200);
        Layered sixth({&newThing, &secondThing, &thirdThing, &fourthThing, &fifth});
        //cout << newThing.draw(300, 300);
	//cout << secondThing.draw(200, 300);
	//cout << thirdThing.draw(300, 400);
        //cout << fourthThing.draw(100, 100);
        //cout << fifth.draw(400, 400);
        cout << sixth.draw(400, 500);
        return 0;
};
