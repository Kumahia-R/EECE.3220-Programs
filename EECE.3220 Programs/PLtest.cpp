/*
	M. Geiger
	EECE.3220: Data Structures
	Code for Summer 2020 Midterm
	PLtest.cpp: code to test PointList functions
*/

#include "PointList.h"	// Implicitly includes Point.h

#include <cstdlib>		// Needed for srand(), rand()
#include <iostream>
using namespace std;

int main() {
	char fn;		// Used to determine which function is being tested
					// 'P' -> printList(), 'F' -> isFull(), 'L' -> isLine()

	PointList pl1, pl2, pl3, pl4;	// pointList objects to be tested
	Point temp;						// Temporary Point object
	double x, y;					// Coordinates to be tested
	unsigned i;						// Loop index

	srand(1);		// Seed RNG

	// Fill PointList objects; pl4 remains empty
	x = -32;
	y = -20;
	for (i = 0; i < 10; i++) {		// Fill pl1 so it's a line--difference
		temp.setX(x);				//    in x, y coordinates same for all 
		temp.setY(y);				//    consecutive points
		pl1.addPoint(temp);
		x += 3.2;
		y += 2.5;
	}

	for (i = 0; i < 20; i++) {			// Fill pl2 with 20 random values between +/- 10
		temp.setX(rand() % 21 - 10);	//    Highly unlikely to be a line
		temp.setY(rand() % 21 - 10);
		pl2.addPoint(temp);
	}

	for (i = 0; i < 50; i++) {			// Fill pl3 with 50 random values between +/- 5
		temp.setX(rand() % 11 - 5);		//    Highly unlikely to be a line
		temp.setY(rand() % 11 - 5);		//	  isFull() will return true for this list
		pl3.addPoint(temp);
	}

	cout << "Which function are you testing? ";
	cin >> fn;

	switch (fn) {
	case 'P':			// Print pl1, pl2, and pl4 (nobody wants to see 50 points in pl3)
		cout << "TESTING printList():\npl1:\n";
		pl1.printList(cout);
		cout << "\npl2:\n";
		pl2.printList(cout);
		cout << "\npl4:\n";
		pl4.printList(cout);
		break;

	case 'F':			// Check isFull()--pl3 should return true, all others should return false
		cout << "TESTING isFull():\n"
			<< "pl1: " << (pl1.isFull() ? "Full\n" : "Not full\n")
			<< "pl2: " << (pl2.isFull() ? "Full\n" : "Not full\n")
			<< "pl3: " << (pl3.isFull() ? "Full\n" : "Not full\n")
			<< "pl4: " << (pl4.isFull() ? "Full\n" : "Not full\n");

		break;
		
	case 'L':
		cout << "TESTING isLine():\n"
			<< "pl1: " << (pl1.isLine() ? "Line\n" : "Not a line\n");

		cout<< "pl2: " << (pl2.isLine() ? "Line\n" : "Not a line\n")
			<< "pl3: " << (pl3.isLine() ? "Line\n" : "Not a line\n")
			<< "pl4: " << (pl4.isLine() ? "Line\n" : "Not a line\n");
		break;
	}

	return 0;
}