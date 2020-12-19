/*
	M. Geiger
	EECE.3220: Data Structures
	Code for Summer 2020 Midterm
	PointList.cpp: PointList member function definitions
*/ 

#include "PointList.h"
#include <iostream>
using namespace std;

/***** FUNCTIONS TO BE WRITTEN FOR MIDTERM EXAM *****/

// printList(): print a single Point object per line
//    to output stream "out"
// Function should print "List empty\n" if no Points in list
// DO NOT ASSUME OUTPUT ALWAYS GOES TO cout
void PointList::printList(ostream& out) {
	for (int i = 0; i < np; i++) {
		out << list[i] << endl;
	}
	if (np == 0) {
		out << "List empty" << endl;
	}
   /***** WRITE YOUR SOLUTION HERE AND REMOVE THIS COMMENT *****/
}

// isFull(): returns true if list has no room 
//    for additional Points; false otherwise
bool PointList::isFull() {
	if (np == 50) {
		return true;
	}
	else {
		return false;
	}
       /***** REMOVE THIS LINE--IT'S HERE ONLY TO ENSURE YOUR CODE COMPILES EVEN IF YOU HAVEN'T WRITTEN THIS FUNCTION *****/
}

// isLine(): returns true if list represents
//   straight line (slope between any two
//   points is the same); false otherwise
bool PointList::isLine() {
	int slopeInit = (list[1].getY() - list[0].getY()) / (list[1].getX() - list[0].getX());
	for (int i = 0; i < np - 1; i++) {
		int slope = (list[i+1].getY() - list[i].getY()) / (list[i+1].getX() - list[i].getX());
		if (slope != slopeInit) {
			return false;
		}
	}
   /***** WRITE YOUR SOLUTION HERE AND REMOVE THIS COMMENT *****/
   
   return true;     /***** REMOVE THIS LINE--IT'S HERE ONLY TO ENSURE YOUR CODE COMPILES EVEN IF YOU HAVEN'T WRITTEN THIS FUNCTION *****/
}
/***** END OF FUNCTIONS TO BE WRITTEN FOR MIDTERM EXAM *****/


// Default constructor--start with empty list
PointList::PointList() : np(0) {}

// Add a single point to list
void PointList::addPoint(Point& p) {
	if (np < 50)
		list[np++] = p;
	else
		cout << "Error: list full\n";
}