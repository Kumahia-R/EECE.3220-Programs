/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Exam 3 code
 * Main program to test BST functions
 */

#include <iostream>
using namespace std;

#include <cstdlib>		// Used for RNG--same seed value, same "random" values

#include "BST.h"

int main() {
	BST b1, b2, b3;	// BSTs
	unsigned i;		   // Loop indexes
	int seed;		   // RNG seed
	int rval;		   // Value used to insert multiples
	unsigned part;	   // Used to determine which BST function is being tested

	// RNG seed--ensures you'll get same "random" values across 
	//   multiple runs with same seed
	cout << "Seed value: ";
	cin >> seed;
	srand(seed);

	// b1 contains 10 values--fill tree, then print contents
	for (i = 0; i < 10; i++)
		b1.insert(rand() % 25);
	cout << "\nAfter filling b1\n";
	b1.printInOrder(cout);

	// b2 contains 15 values--each loop iteration adds 	
	//   2 copies of one random value (to ensure
	//   duplicates) and one other value
	for (i = 0; i < 5; i++) {
		rval = rand() % 50;
		b2.insert(rval);
		b2.insert(rand() % 50);
		b2.insert(rval);
	}
	cout << "\nAfter filling b2\n";
	b2.printInOrder(cout);

	// b3 is empty, and the output reflects that
	cout << "\nWithout filling b3\n";
	b3.printInOrder(cout);

	// Testing exam functions
	cout << "\nWhich part? ";
	cin >> part;

	switch (part) {
	case 1:					// Testing findMin()
		cout << "\nMinimum value in b1 = " << b1.findMin() << endl;
		cout << "\nMinimum value in b2 = " << b2.findMin() << endl;
		cout << "\nMinimum value in b3 (should be 0) = " << b3.findMin() << endl;
		break;

	case 2:					// Testing countNodes()
		cout << "\nNumber of nodes in b1 = " << b1.countNodes() << endl;
		cout << "\nNumber of nodes in b2 = " << b2.countNodes() << endl;
		cout << "\nNumber of nodes in b3 = " << b3.countNodes() << endl;
		break;

	case 3:					// Testing printDuplicates()
		cout << "\nTesting printDuplicates() for b1:\n";
		b1.printDuplicates(cout);
		cout << "\nTesting printDuplicates() for b2:\n";
		b2.printDuplicates(cout);
	}

	return 0;
}