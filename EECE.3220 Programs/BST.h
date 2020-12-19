#pragma once
/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Exam 3 code
 * Header file for BST class
 *
 * In definitions below, nullptr == NULL
 */

#include <iostream>
using namespace std;

class BST {
public:

	/************ EXAM 3 FUNCTIONS TO BE COMPLETED ************/
	int findMin();						   	// Find the minimum value in the BST
												  //   Returns 0 if tree empty (so you 
												  //   shouldn't call it on an empty tree)
	unsigned countNodes();					// Count all nodes in tree
	void printDuplicates(ostream& out);	// Finds all duplicates 

	/**** FUNCTIONS BELOW THIS LINE ARE ALREADY DEFINED FOR YOU--DO NOT CHANGE ****/
	BST() : root(nullptr) {}
	bool empty();						   // Returns true if tree empty; false otherwise
	void insert(int v);				   // Adds new node with value v
	bool remove(int v);			      // Removes node with value v
											 //   Returns true if node found & removed; false otherwise
	bool search(int v);					// Returns true if v in tree; false otherwise
	void printInOrder(ostream& out);	// Prints tree contents in order

private:

	// BST node to be used in implementation
	class BSTNode {
	public:
		BSTNode(int v) : val(v), left(nullptr), right(nullptr) {}
		int val;					      // Value stored in node
		BSTNode* left, * right;		// Pointers to left and right subtrees
	};

	BSTNode* root;			// Root of tree

	// Recursive helper functions--called only in other BST functions
	void insertNode(BSTNode* tree, BSTNode* n);
	bool removeNode(BSTNode* tree, BSTNode* parent, int v);
	BSTNode* searchNode(BSTNode* tree, int v);
	void printNode(BSTNode* tree, ostream& out);

	/***** ADD YOUR OWN HELPER FUNCTION PROTOTYPES BELOW THIS LINE *****/
	void findNode(BSTNode* tree, int& numNodes);
	void findDup(BSTNode* tree, int& dupNum, int dupVal);
};