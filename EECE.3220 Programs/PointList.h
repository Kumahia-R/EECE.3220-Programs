/*
	M. Geiger
	EECE.3220: Data Structures
	Code for Summer 2020 Midterm
	PointList.h: PointList class definition
*/ 

#ifndef POINTLIST_H
#define POINTLIST_H
#include "Point.h"

class PointList {
private:
	Point list[50];      // A PointList can hold up to 50 points
	unsigned np;         // Actual number of points stored in array
public:
	PointList();					      // Default constructor (empty list)
	void addPoint(Point& p);		   // Add a single point at the end of the list
	void printList(ostream& out);	   // Print every point in list
	bool isFull();					      // Returns true if list is full
	bool isLine();					      // Returns true if list represents a line
};

#endif   // POINTLIST_H