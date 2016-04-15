// Example.cpp
// Testing our custom Postscript library

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Polygon.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Circle newThing = Circle(72);
	Rectangle secondThing = Rectangle(100, 200);
	cout << newThing.draw(300, 300);
	cout << secondThing.draw(200, 300);
	return 0;
};
