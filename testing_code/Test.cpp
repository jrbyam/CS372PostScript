#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Horizontal.h"
#include "Layered.h"
#include "Polygon.h"
#include "Smiley.h"
#include "Square.h"
#include "Triangle.h"
#include "Vertical.h"

// The following tests compare our output to exact strings. We tested these exact strings by compiling them as Postscript
// code and confirming that the correct visual output was produced.

// Test that each simple shape provides the expected, unmodified output
TEST_CASE("Simple Shapes", "Circle") {
	Circle myCircle(72);
	REQUIRE(myCircle.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\n");
}

TEST_CASE("Simple Shapes 1", "Rectangle") {
	Rectangle myRect(72, 144);
	REQUIRE(myRect.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\n-36.000000 -72.000000 moveto\n72.000000 0 rlineto\n0 144.000000 rlineto\n-72.000000 0 rlineto\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Simple Shapes 2", "Square") {
	Square mySquare(72);
	REQUIRE(mySquare.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Simple Shapes 3", "Triangle") {
	Triangle myTri(72);
	REQUIRE(myTri.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -20.810100 moveto\n0.066226 41.581918 lineto\n-36.066104 -20.695324 lineto\nclosepath\nstroke\ngrestore");
}

// Test that each compound shape provides the expected output based on the given list of shapes
TEST_CASE("Compound Shapes 1", "Horizontal") {
	Circle one(72);
	Square two(72);
	Horizontal myHoriz({&one, &two});
	REQUIRE(myHoriz.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\ngsave\n72 0 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore\ngrestore");
}

TEST_CASE("Compound Shapes 2", "Layered") {
	Circle one(72);
	Square two(72);
	Layered myLayer({&one, &two});
	REQUIRE(myLayer.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Compound Shapes 3", "Vertical") {
	Circle one(72);
	Square two(72);
	Vertical myVert({&one, &two});
	REQUIRE(myVert.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\ngsave\n0 -72 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore\ngrestore");
}

TEST_CASE("Compound Shapes 4", "Smiley") {
	Smiley mySmile(72);
	REQUIRE(mySmile.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc\n255 255 0 setrgbcolor fill\n0 0 0 setrgbcolor\n0 0 72.000000 0 360 arc stroke\ngrestore");
}

// Test Rotation
TEST_CASE("Rotation 1", "Polygon Rotate") {
	Polygon myPoly(5, 72);
	myPoly.rotate(90);
	REQUIRE(myPoly.draw(100, 200) == "gsave\n100 200 translate\n90 rotate\n1.000000 1.000000 scale\n36.000000 -49.582954 moveto\n58.292843 18.878927 lineto\n0.097588 61.273647 lineto\n-58.232412 19.064511 lineto\n-36.157754 -49.468032 lineto\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Rotation 2", "Vertical Rotate") {
	Circle one(72);
	Square two(72);
	Vertical myVert({ &one, &two });
	myVert.rotate(450);
	REQUIRE(myVert.draw(100, 200) == "gsave\n100 200 translate\n450 rotate\n1.000000 1.000000 scale\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\ngsave\n0 -72 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore\ngrestore");
}

// Test Scaling
TEST_CASE("Scaling 1", "Polygon Scale") {
	Polygon myPoly(6, 72);
	myPoly.scale(2, 1);
	REQUIRE(myPoly.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n2.000000 1.000000 scale\n36.000000 -62.392070 moveto\n72.033098 -0.057362 lineto\n36.099323 62.334656 lineto\n-35.900585 62.449327 lineto\n-72.032915 0.172086 lineto\n-36.198555 -62.277083 lineto\nclosepath\nstroke\ngrestore");
}

TEST_CASE("Scaling 2", "Layered Scale") {
	Circle one(72);
	Square two(72);
	Layered myLayer({ &one, &two });
	myLayer.scale(1, 2);
	REQUIRE(myLayer.draw(100, 200) == "gsave\n100 200 translate\n0 rotate\n1.000000 2.000000 scale\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n0 0 72.000000 0 360 arc stroke\ngrestore\ngsave\n0 0 translate\n0 rotate\n1.000000 1.000000 scale\n36.000000 -36.028679 moveto\n36.057336 35.971298 lineto\n-35.942573 36.085969 lineto\n-36.114580 -35.913826 lineto\nclosepath\nstroke\ngrestore");
}

// Test both Scaling and Rotation
TEST_CASE("Rotation Scaling 1", "Polygon") {
	Polygon myPoly(6, 72);
	myPoly.scale(2, 1);
	myPoly.rotate(-90);
	REQUIRE(myPoly.draw(100, 200) == "gsave\n100 200 translate\n-90 rotate\n2.000000 1.000000 scale\n36.000000 -62.392070 moveto\n72.033098 -0.057362 lineto\n36.099323 62.334656 lineto\n-35.900585 62.449327 lineto\n-72.032915 0.172086 lineto\n-36.198555 -62.277083 lineto\nclosepath\nstroke\ngrestore");
}