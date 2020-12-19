#pragma once
/*
 * EECE.3220: Data Structures
 * Instructor: M. Geiger
 * Linked list definition
 *
 * LList.h: class definition
 */

#ifndef LLIST_H
#define LLIST_H

#include <iostream>
using std::ostream;

class LList {
public:
	/***** FUNCTION TO BE WRITTEN FOR EXAM 3 *****/
	void sort();			// Sort linked list using selection sort

	/***** FUNCTIONS BELOW THIS LINE ARE ALREADY WRITTEN--DO NOT MODIFY *****/
	LList();				 // Default constructor
	~LList();				 // Destructor
	bool empty();			 // True if list is empty
	void insert(int v);		 // Add new value to list
	void remove(int v);		 // Remove node with v

	void display(ostream& out);	// Print contents of list
								//  (could of course write as
								//  overloaded operator)
private:

	/****************************************************************
	  Slightly different setup than we've seen before, as Node class
		is defined *inside* LList class.
	  Benefits:
		By making "Node" a member of LList, LList functions can
		  directly refer to Node data members val and next. No
		  need to write/call accessor functions for Node, so
		  fewer files in solution + no function call overhead on
		  simple data accesses. Node data members are "public" to
		  LList functions but "private" to outside world.
	  Downside:
		This implementation of Node can *only* be used inside LList.
		  If you want Node objects in other classes, have to redefine.
	****************************************************************/
	class Node {
	public:
		int val;		// Value in each node--could be generalized
						//   using templates
		Node* next;		// Pointer to next node
	};

	Node* first;	// Pointer to first node
};

#endif