// Computing Structures Fall 2022
// Project 5

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////
// Class ArrayBTNode
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBTNode
{
protected:
	// Instance Variables
	DT *_info;
	int _left;
	int _right;

public:
	// Constructors and Destructor
	ArrayBTNode();
	ArrayBTNode(DT &info);
	~ArrayBTNode();

	// getter Methods
	DT* getinfo();
	int getleft();
	int getright();

	// setter Methods
	void setInfo(DT &info);
	void setInfoNull(); // Sets _info to Null
	void setLeft(int left);
	void setRight(int right);

	// Display Method
	// Outputs data in _info, _left, _right
	void display();

	// Overloaded Comparison Operators
	// Used for comparing _info field with other ArrayBTNodes
	bool operator<(const ArrayBTNode<DT> &x);
	bool operator>(const ArrayBTNode<DT> &x);
	bool operator==(const ArrayBTNode<DT> &x);
	bool operator>=(const ArrayBTNode<DT> &x);
	bool operator<=(const ArrayBTNode<DT> &x);
	bool operator!=(const ArrayBTNode<DT> &x);

	// TODO: Overloaded Ostream Operator - Uses display method to output ArrayBTNode contents
};





////////////////////////////////////////////////////////////////////////////////////////
// Class ArrayBST
////////////////////////////////////////////////////////////////////////////////////////

template <class DT>
class ArrayBST
{
protected:
	// Instance Variables
	vector<ArrayBTNode<DT> > _tree;    // Vector of ArrayBTNodes used to create a tree
	int _rootIndex;            // Index of the root node in _tree
	int _numNodes;             // Number of nodes in the tree
	int _size;                 // Maximum size of the _tree array
	stack<int> _freeLocations; // Stack containing indexes of freeLocations in the _tree array

public:
	// Constructors and Destructor
	ArrayBST();
	ArrayBST(int k); // initialize the vector with NULL nodes and fill the stack
	~ArrayBST();

	// Accessor Methods
	bool isEmpty() const;
	int Height();
	int Size();
	int rootIndex();
	int maxSize();

	// Mutator Methods
	void setData(int index, DT &value);
	void setLeft(int index, int value);
	void setRight(int index, int value);

	// Display methods and traversals
	void display(ostream &os) const;
	void displayPreOrder(ostream &os) const;
	void displayInOrder(ostream &os) const;
	void printRaw(); // Display the array and all of its contents

	// BST Specific Methods
	void insert(DT &object);
	bool find(DT &object);
	int findIndex(DT &object);
	void remove(DT &object); // extra credit

	// TODO: Overridden ostream operator for ArrayBST - this will call the pre order and in order methods
};






////////////////////////////////////////////////////////////////////////////////////////
// Main Method
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Get input for the size of the tree
	int inputSize;
	cin >> inputSize;

	// Create a BST of the size inputSize
	ArrayBST<int> myBST = ArrayBST<int>(inputSize);

    // TODO: input loop for commands





	return 0;
}