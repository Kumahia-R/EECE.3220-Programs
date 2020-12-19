/*
 * M. Geiger
 * EECE.3220: Data Structures
 *
 * Exam 3 code
 * Source file for BST class
 *
 * In definitions below, nullptr == NULL
 */

#include "BST.h"

 /************ EXAM 3 FUNCTIONS TO BE COMPLETED ************/

 // Find and return the minimum value in the BST
 //   Returns 0 if tree is empty
int BST::findMin() {
	/***** ADD YOUR OWN SOLUTION *****/
	if (empty()) {
		return 0;
	}
	else {
		BST* minAdd = new BST;
		BST& min = *minAdd;
		*minAdd = *this;
		int minVal = min.root->val;
		int searchVal = minVal;
		while (searchVal > 0) {
			if (min.search(--searchVal)) {
				minVal = searchVal;
			}
		}
		return minVal;
	}
}

// Count all nodes in tree
// HINT: You may want a helper function--recursive or iterative--that visits each node
unsigned BST::countNodes() {
	/***** ADD YOUR OWN SOLUTION *****/
	if (empty()) {
		return 0;
	}
	else {
		int numCount = 0;
		int *nodeCount = new int;
		*nodeCount = numCount;
		findNode(root, *nodeCount);
		return *nodeCount;
	}
}

// Finds all duplicates and prints them to out
// Hint: You may want a helper function to traverse the tree
void BST::printDuplicates(ostream& out) {
	/***** ADD YOUR OWN SOLUTION *****/
	BST* tmp1 = new BST;
	*tmp1 = *this;
	BST& tmpAdd1 = *tmp1;
	int dupNum = 0;
	int* isDup = new int;
	*isDup = dupNum;
	int dupVal = tmpAdd1.root->val;
	findDup(this->root, *isDup, dupVal);
	out << "Duplicates:";
	if (*isDup > 1) {
		out << " " << dupVal;
		tmpAdd1.remove(dupVal);
	}
	while (tmpAdd1.root != NULL) {
		*isDup = 0;
		if (tmpAdd1.root->left == NULL) {
			while (tmpAdd1.root->right != NULL) {
				findDup(tmpAdd1.root, *isDup, tmp1->root->val);
				if (*isDup > 1) {
					out << " " << tmp1->root->val;
					tmpAdd1.remove(tmp1->root->val);
				}
				tmpAdd1.root = tmpAdd1.root->right;
			}
		}
		else {
			tmpAdd1.root = root->left;
		}
	}

	if (*isDup > 1) {
		cout << " " << *isDup;
	}
}

/************ END EXAM 3 FUNCTIONS TO BE COMPLETED ************/


/**** FUNCTIONS BELOW THIS LINE ARE ALREADY DEFINED FOR YOU--DO NOT CHANGE ****/
// Returns true if tree empty; false otherwise
bool BST::empty() {
	return (root == nullptr);
}

// Adds new node with value v
void BST::insert(int v) {
	BSTNode* n = new BSTNode(v);
	if (root == nullptr)
		root = n;
	else
		insertNode(root, n);
}

// Removes node with value v
//   Returns true if node found & removed; false otherwise
bool BST::remove(int v) {
	return removeNode(root, nullptr, v);
}

// Returns true if v in tree; false otherwise
bool BST::search(int v) {
	return (searchNode(root, v) != nullptr);
}

// Prints tree contents in order
void BST::printInOrder(ostream& out) {
	if (root == nullptr)
		out << "Tree is empty\n";

	else {
		out << "Tree contents:\n";
		printNode(root, out);
		out << "\n";
	}
}


// Recursive helper functions
void BST::insertNode(BSTNode* tree, BSTNode* n) {
	if (n->val < tree->val) {
		if (tree->left == nullptr)
			tree->left = n;
		else
			insertNode(tree->left, n);
	}
	else {
		if (tree->right == nullptr)
			tree->right = n;
		else
			insertNode(tree->right, n);
	}
}

// Recursively remove node with value v
//   Takes parent pointer so we don't need another search function to find it
bool BST::removeNode(BSTNode* tree, BSTNode* parent, int v) {
	if (tree == nullptr)		// Base case 1
		return false;

	if (tree->val == v) {		// Found node--base case 2

		// Node to remove is leaf
		if (tree->left == nullptr && tree->right == nullptr) {
			if (parent->right == tree)
				parent->right = nullptr;
			else
				parent->left = nullptr;
			delete tree;
		}

		// Node has one child on right
		else if (tree->left == nullptr) {
			if (parent->right == tree)
				parent->right = tree->right;
			else
				parent->left = tree->right;
			delete tree;
		}

		// Node has one child on left
		else if (tree->right == nullptr) {
			if (parent->right == tree)
				parent->right = tree->left;
			else
				parent->left = tree->left;
			delete tree;
		}

		// Node has two children
		else {

			// Find in-order successor, copy data from that node to "tree", then delete successor
			BSTNode* s = tree->right;
			BSTNode* sp = tree;			// Parent node to pass to delete function
			while (s->left != nullptr) {
				sp = s;
				s = s->left;
			}

			tree->val = s->val;
			removeNode(s, sp, s->val);
		}

		return true;
	}

	else if (v < tree->val)		// Go left
		return removeNode(tree->left, tree, v);

	else						// Go right
		return removeNode(tree->right, tree, v);
}

// Returns node where v is found or nullptr otherwise
BST::BSTNode* BST::searchNode(BSTNode* tree, int v) {
	if (tree == nullptr || v == tree->val)
		return tree;

	else if (v < tree->val)
		return searchNode(tree->left, v);

	else
		return searchNode(tree->right, v);
}

// Recursively visit all nodes in order and print their values
void BST::printNode(BSTNode* tree, ostream& out) {
	if (tree != nullptr) {
		printNode(tree->left, out);
		out << " " << tree->val;
		printNode(tree->right, out);
	}
}
void BST::findNode(BSTNode* tree, int& numNodes) {
	if (tree != NULL) {
		numNodes++;
		findNode(tree->left, numNodes);
		findNode(tree->right, numNodes);
	}
}
void BST::findDup(BSTNode* tree, int& dupNum, int dupVal) {
	if (tree != nullptr && tree->val == dupVal) {
		dupNum++;
		if (tree->left != NULL) {
			findDup(tree->left, dupNum, dupVal);
		}
		if (tree->right != NULL) {
			findDup(tree->right, dupNum, dupVal);
		}
	}
	else {
		if (tree->left != NULL) {
			findDup(tree->left, dupNum, dupVal);
		}
		if (tree->right != NULL) {
			findDup(tree->right, dupNum, dupVal);
		}
	}
}