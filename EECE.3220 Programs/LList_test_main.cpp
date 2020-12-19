/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList_test_main.cpp: test program for sort() function
 */

#include "LList.h"

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	LList L1, L2;		// Linked lists to use for testing

	unsigned i;		// Loop indexes
	int seed;		// RNG seed

	// RNG seed--ensures you'll get same "random" values across 
	//   multiple runs with same seed
	cout << "Seed value: ";
	cin >> seed;
	srand(seed);

	// Fill lists
	for (i = 0; i < 10; i++) {
		L1.insert(rand() % 50);
		L2.insert(rand() % 50);
	}

	// Print lists before sorting
	cout << "Before sorting:\nL1: ";
	L1.display(cout);
	cout << "\nL2: ";
	L2.display(cout);

	// Sort and print lists again
	L1.sort();
	L2.sort();
	cout << "After sorting:\nL1: ";
	L1.display(cout);
	cout << "\nL2: ";
	L2.display(cout);

	return 0;
}