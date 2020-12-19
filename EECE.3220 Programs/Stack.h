#pragma once
/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Header file for in-class stack example
 * Stack class definition
 *
 * FOR EXAM 2, ADDED TWO FUNCTIONS TO BE WRITTEN
 *  DEFINITIONS WILL BE WRITTEN IN STACK.CPP
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
public:
	// FUNCTIONS TO BE WRITTEN FOR EXAM 2
	void print(ostream& out);			// Print stack contents from top to bottom, one value per line
											  // Also prints stack capacity and # values currently in stack
	void swap(Stack& aStack);			// Exchange contents of calling object with argument aStack
	// END OF FUNCTIONS TO BE WRITTEN FOR EXAM 2

	Stack(unsigned maxSize = 1024);		// Constructor
	~Stack();						      	// Destructor
	bool empty() const;					   // Returns true if stack empty
	void push(const double& val);		   // Push val to top of stack
	void pop();						      	// Remove top of stack
	double top();						      // Read contents of top of stack
private:
	unsigned cap;	// Capacity (max size) of stack
	int tos;		   // Index for top of stack
	double* list;	// The actual data stored on the stack
};

#endif   // STACK_H