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
#include <iostream>
using std::cout;
using std::endl;

int main() {
        Circle firstThing(72);
	Circle newThing(72);
        newThing.scale(2, 1);
        newThing.rotate(90);
	Rectangle secondThing(100, 200);
	secondThing.rotate(-90);
        secondThing.scale(2, 2);
        Polygon thirdThing(8, 50);
        thirdThing.scale(3, 5);
        thirdThing.rotate(180);
        Square fourthThing(75);
        Triangle fifth(200);
        Layered sixth({&newThing, &secondThing, &thirdThing, &fourthThing, &fifth});
        sixth.scale(.5, .5);
        sixth.rotate(90);
        Vertical seventh({&newThing, &secondThing, &thirdThing});
        seventh.scale(.5, .5);
        seventh.rotate(1080);
        Horizontal eighth({&newThing, &firstThing});
        eighth.scale(.5, .5);
        eighth.rotate(-90);
        Horizontal ninth({&seventh, &eighth});
        Layered tenth({&firstThing, &newThing, &secondThing, &thirdThing, &fourthThing, &fifth, &sixth, &seventh, &eighth, &ninth});
        Smiley eleventh(50);
        //eleventh.scale(-2, 1);
        Horizontal twelvth({ &firstThing, &secondThing, &eleventh });
        twelvth.scale(-1, 1);
        //cout << newThing.draw(300, 300);
        //cout << firstThing.draw(300, 300);
	//cout << secondThing.draw(200, 300);
	//cout << thirdThing.draw(300, 300);
        //cout << fourthThing.draw(100, 100);
        //cout << fifth.draw(400, 400);
        //cout << sixth.draw(300, 300);
        //cout << seventh.draw(300, 300);
        //cout << eighth.draw(300, 300);
        //cout << ninth.draw(300, 300);
        //cout << tenth.draw(300, 300);
        //cout << eleventh.draw(300, 300);
        cout << twelvth.draw(300, 300);
        return 0;
};
