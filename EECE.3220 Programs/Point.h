/* 
	M. Geiger
	EECE.3220: Data Structures
	Point example code for in-class operator overloading example
	  (Modified version of composition example)
	Class definition
*/

#ifndef Point_h		// Header guard
#define Point_h
	
#include <iostream>	// Necessary for printPoint prototype
using std::ostream;	//  ... but it doesn't work without
					//  indicating what part of <iostream>
					//  we're using

class Point {
public:
	Point();						// Default constructor
	Point(double X, double Y);		// Parameterized constructor
	void setX(double newX);			// Set X coordinate
	void setY(double newY);			// Set Y coordinate
	double getX();					// Returns X coordinate
	double getY();					// Returns Y coordinate

	// OVERLOADED OPERATORS
	Point& operator =(const Point &rhs);	// Assignment
											// e.g., p1 = p2; --> p1.operator=(p2);
	bool operator ==(const Point &rhs);		// Equality

	friend ostream& operator <<(ostream& out, const Point& p);	// Output operator
private:
	double xCoord;		// X coordinate
	double yCoord;		// Y coordinate
};

#endif