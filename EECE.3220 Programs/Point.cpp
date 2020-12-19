/*
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class operator overloading example
	  (Modified version of composition example)
	Function definitions
*/

#include "Point.h"

// Default constructor
Point::Point() : xCoord(0), yCoord(0) {}

// Parameterized constructor
Point::Point(double X, double Y) : xCoord(X), yCoord(Y) {}

// "Set" functions
void Point::setX(double newX) {
	xCoord = newX;
}

void Point::setY(double newY) {
	yCoord = newY;
}

// "Get" functions
double Point::getX() {
	return xCoord;
}

double Point::getY() {
	return yCoord;
}


// OVERLOADED OPERATORS
// p2 = p1;  --> p2.operator =(p1);
Point& Point::operator =(const Point& rhs) {

	// Ensure no self-assignment (for example, p1 = p1)
	if (!(*this == rhs)) {
		
		// xCoord == this->xCoord (two expressions are equivalent)		
		xCoord = rhs.xCoord;
		yCoord = rhs.yCoord;
	}

	return *this;
}

// Example usage: if (p1 == p2) { }
bool Point::operator ==(const Point& rhs) {
	if (xCoord == rhs.xCoord && yCoord == rhs.yCoord)
		return true;
	else
		return false;

	/* Could write as:
	return (xCoord == rhs.xCoord && yCoord == rhs.yCoord);
	*/
}

// Example usage:  cout << p1;   or
//   cout << p1 << " " << p2;
ostream& operator <<(ostream& out, const Point& p) {
	out << "(" << p.xCoord << ", " << p.yCoord << ")";
	return out;
}