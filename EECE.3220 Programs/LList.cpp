/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList.cpp: function definitions
 *
 * MODIFIED FOR EXAM 3 AS FOLLOWS:
 *  - One new function to write, sort()
 *  - insert() now creates unordered list
 *  - remove() searches full list
 *  - display() prints all values on one line
 */

#include "LList.h"
using namespace std;

/***** EXAM 3 FUNCTION TO BE WRITTEN *****/
void LList::sort() {			// Sort linked list using selection sort
   /***** ADD YOUR OWN SOLUTION *****/
	Node* lower = first;
	Node* higher = lower;
	int temp;
	while (lower != NULL) {
		while (higher != NULL) {
			if (lower->val > higher->val) {
				temp = lower->val;
				lower->val = higher->val;
				higher->val = temp;
			}
			higher = higher->next;
		}
		lower = lower->next;
		if (lower != NULL) {
			higher = lower->next;
		}
	}
}

/***** FUNCTIONS BELOW THIS LINE ARE ALREADY WRITTEN--DO NOT MODIFY *****/

// Default constructor
LList::LList() : first(NULL)
{}

// Destructor
LList::~LList() {
	Node* temp;
	while (first != NULL) {
		temp = first;
		first = first->next;
		delete temp;
	}
}

// True if list is empty
bool LList::empty() {
	return (first == NULL);
}

// Add new value to list
/***** MODIFIED FOR EXAM 3 TO CREATE UNORDERED LIST *****/
void LList::insert(int v) {

	// Allocate new node and place at beginning of list
	Node* newNode = new Node;
	newNode->val = v;
	newNode->next = first;
	first = newNode;
}

// Remove node with v	
void LList::remove(int v) {
	Node* prev;		// Predecessor of node to be deleted
	Node* cur;		// Node to be deleted

	// Find node, if it's in list
	cur = first;
	prev = NULL;
	while (cur != NULL && cur->val != v) {		/***** MODIFIED FOR EXAM 3--NO LONGER ASSUMES LIST ORDERED *****/
		prev = cur;
		cur = cur->next;
	}

	// Didn't find node
	if (cur == NULL) {
		cout << "Node with value " << v << " not found\n";
		return;
	}

	// Otherwise, remove node
	if (prev == NULL)			// Special case for first node
		first = cur->next;
	else
		prev->next = cur->next;
	delete cur;
}

// Display contents of list
void LList::display(ostream& out) {
	Node* ptr = first;

	while (ptr != NULL) {
		out << ptr->val << ' ';
		ptr = ptr->next;
	}
	out << '\n';
}