/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Source file for in-class stack example
 * Stack member function definitions
 *
 * COMPLETE THE FUNCTION DEFINITIONS IN THIS FILE
 *  FOR THE print() AND swap() FUNCTIONS
 */

#include "Stack.h"
#include <iostream>
using std::cout;
using std::endl;

// FUNCTIONS TO BE WRITTEN FOR EXAM 2
// Print stack contents from top to bottom, one per line
// Also prints stack capacity and # values currently in stack
void Stack::print(ostream& out) {
	// COMPLETE THIS FUNCTION TO EARN CREDIT FOR PART 1   
	Stack *tmpAdd = new Stack;
	Stack& tmpPrint = *tmpAdd;
	*tmpAdd = *this;
	out << "Stack capacity: " << cap << endl;
	out << "Current size: " << tos + 1 << endl;
	out << "Current contents:" << endl;
	if (tmpPrint.empty()) {
		out << "None--stack empty"<< endl;
	}
	else {
		while (!tmpPrint.empty()) {
			out << tmpPrint.top() << endl;
			tmpPrint.pop();
		}
	}
}

// Exchange contents of calling object with argument aStack
void Stack::swap(Stack& aStack) {
	// COMPLETE THIS FUNCTION TO EARN CREDIT FOR PART 2
	Stack *tmp1 = new Stack;
	Stack *tmp2 = new Stack;
	*tmp1 = *this;
	*tmp2 = aStack;
	Stack& tmpAdd1 = *tmp1;
	Stack& tmpAdd2 = *tmp2;
	aStack = tmpAdd1;
	*this = tmpAdd2;
}
// END OF FUNCTIONS TO BE WRITTEN FOR EXAM 2

/***********************************************************************************/
/* ORIGINAL ARRAY-BASED STACK FUNCTIONS--DO NOT MODIFY CODE AFTER THIS POINT       */
/***********************************************************************************/

// Constructor
Stack::Stack(unsigned maxSize) :
	cap(maxSize), tos(-1)
{
	list = new double[cap];
}

// Destructor
Stack::~Stack() {
	delete[] list;
}

// Returns true if stack empty
bool Stack::empty() const {
	// Could write as:
	//    return (tos == -1);

	if (tos == -1)
		return true;
	else
		return false;
}

// Push val to top of stack
void Stack::push(const double& val) {
	if (tos == (int)cap - 1)
		cout << "Stack is full" << endl;
	else {
		tos++;
		list[tos] = val;

		// Could have written: list[++tos] = val;
	}
}

// Remove top of stack
void Stack::pop() {
	if (empty())
		cout << "Stack is empty" << endl;
	else
		tos--;
}

// Read top of stack
double Stack::top() {
	if (empty()) {
		cout << "Stack is empty" << endl;
		return list[cap - 1];		// Have to return something ...
	}
	else
		return list[tos];
}