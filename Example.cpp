// Example.cpp
// Testing our custom Postscript library

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	Circle newThing = Circle(72);
	Rectangle secondThing = Rectangle(10, 20);

	cout << newThing.draw();
	cout << secondThing.draw();

	getchar();
	return 0;
};