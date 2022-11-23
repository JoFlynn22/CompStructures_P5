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
	bool operator<(const ArrayBTNode<DT> &x);   // took out const for all operators 
	bool operator>(const ArrayBTNode<DT> &x);
	bool operator==(const ArrayBTNode<DT> &x);
	bool operator>=(const ArrayBTNode<DT> &x);
	bool operator<=(const ArrayBTNode<DT> &x);
	bool operator!=(const ArrayBTNode<DT> &x);

	// TODO: Overloaded Ostream Operator - Uses display method to output ArrayBTNode contents
    friend ostream& operator<<(ostream &os, const ArrayBTNode<DT> &x);
};

template<class DT>
ArrayBTNode<DT>::ArrayBTNode()  // setting info to null and left/right to show there is nothing there
{
    _info = NULL;
    _left = -1;
    _right = -1;
}

template<class DT>
ArrayBTNode<DT>::ArrayBTNode(DT &info)  // constructor for info making a new info
{
    // going to be called directly
    // allocate memory to _info, this is correct
    _info = new DT(info);
    _left = -1;
    _right = -1;
}

template<class DT>
ArrayBTNode<DT>::~ArrayBTNode() // destructor for info
{
    // if theres no _info, then there shouldnt a right or left
    delete _info;
}

template<class DT>
DT* ArrayBTNode<DT>::getinfo()  // getter for info
{
    return _info;
}

template<class DT>
int ArrayBTNode<DT>::getleft()  // getter for left tree
{
    return _left;
}

template<class DT>
int ArrayBTNode<DT>::getright() // getter for right tree
{
    return _right;
}

template<class DT>
void ArrayBTNode<DT>::setInfo(DT &info) // setter for info
{
    // this is correct -> Adi's office hours
    // delete previous _info 
    delete _info;

    _info = new DT(info);   // makes new info
}

template<class DT>
void ArrayBTNode<DT>::setInfoNull() // setter for initially setting info to NULL
{
    _info = NULL;
}

template<class DT>
void ArrayBTNode<DT>::setLeft(int left) // setter for left node
{
    _left = left;
}

template<class DT>
void ArrayBTNode<DT>::setRight(int right)   // setter for right node
{
    _right = right;
}

template<class DT>
ostream& operator<<(ostream &os, const ArrayBTNode<DT> &x) // ostream for display
{
    x.display();
    return os;
}

template<class DT>
void ArrayBTNode<DT>::display() // come back and figure out display later
{
    cout << "Info: " << *_info << ", "; // order goes Index(in ArrayBST), Info, Left, Right
    cout << "Left: " << _left << ", ";
    cout << "Right: " << _right << endl;
}

template<class DT>
bool ArrayBTNode<DT>::operator<(const ArrayBTNode<DT> &x)   // operator for <
{
    return *_info < *x._info;
}

template<class DT>
bool ArrayBTNode<DT>::operator>(const ArrayBTNode<DT> &x)   // operator for >
{
    return *_info > *x._info;
}

template<class DT>
bool ArrayBTNode<DT>::operator==(const ArrayBTNode<DT> &x)  // operator for ==
{
    return *_info == *x._info;
}

template<class DT>
bool ArrayBTNode<DT>::operator>=(const ArrayBTNode<DT> &x)  // operator for >=
{
    return *_info >= *x._info;
}

template<class DT>
bool ArrayBTNode<DT>::operator<=(const ArrayBTNode<DT> &x)  // operator for <=
{
    return *_info <= *x._info;
}

template<class DT>
bool ArrayBTNode<DT>::operator!=(const ArrayBTNode<DT> &x)  // operator for !=
{
    return *_info != *x._info;
}


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
	void display(ostream &os);
	void displayPreOrder(ostream &os);
    void _preorder(int pos);
	void displayInOrder(ostream &os);
    void _inorder(int pos);
	void printRaw(); // Display the array and all of its contents

	// BST Specific Methods
	void insert(DT &object);
	bool find(DT &object);
    bool _find(DT &object, int pos);
	int findIndex(DT &object);
	void remove(DT &object); // extra credit

	// TODO: Overridden ostream operator for ArrayBST - this will call the pre order and in order methods
    friend ostream& operator<<(ostream &os, const ArrayBST<DT> &x);
};

template<class DT>
ArrayBST<DT>::ArrayBST() // constructor for arraybst, initializing the root index to -1 and everything else to 0
{
    _rootIndex = -1;
    _numNodes = 0;
    _size = 0;
}

template<class DT>
ArrayBST<DT>::ArrayBST(int k) // constructor for arraybst
{
    // Adi 11/18/22
    // should be right now 
    _rootIndex = k-1;    // root index at k-1 because the root will be at the bottom of stack 
    _numNodes = 0;
    _size = k;
    _tree.reserve(k);   // reserving the size of the vector with the number in main 

    for (int i = 0; i < k; i++)
    {
        _freeLocations.push(i); // pushing all the indexes into the stack
        _tree.push_back(ArrayBTNode<DT>()); // initializes vector to have all empty nodes
    }
}

template<class DT>
ArrayBST<DT>::~ArrayBST() // destructor for arraybst
{
    // https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/

    //_tree.clear(); // clearing the vector

    _rootIndex = -1;    // setting everything back to 0
    _numNodes = 0;
    _size = 0;

}

template<class DT>
bool ArrayBST<DT>::isEmpty() const // check if empty, true if numNodes is equal to 0
{
    return _freeLocations.size() == 0;
}

template<class DT>
int ArrayBST<DT>::Height() // height of tree
{
    int left = 1;
    int right = 1;
    int temp = _rootIndex;

    while (temp != -1)
    {
        if (_tree[temp].getleft() != -1)    // should go left first and get the left tree height
        {
            temp = _tree[temp].getleft();
            left++;
        }
        else if (_tree[temp].getright() != -1)  // left side still needs to go right in some cases
        {
            temp = _tree[temp].getright();
            left++;
        }
        else
        {
            break;
        }
    }

    while(temp != -1)
    {
        if (_tree[temp].getright() != -1)   // should go right first and get the right tree height
        {
            temp = _tree[temp].getright();
            right++;
        }
        else if (_tree[temp].getleft() != -1)   // right side still needs to go left in some cases
        {
            temp = _tree[temp].getleft();
            right++;
        }
        else
        {
            break;
        }
    }

    if (left >= right)   // returns the larger height
    {
        return left;
    }
    else
    {
        return right;
    }

    return 0;
}

template<class DT>
int ArrayBST<DT>::Size() // size of tree = number of nodes since size is max size of tree
{
    return _numNodes;
}

template<class DT>
int ArrayBST<DT>::rootIndex() // first node in the tree
{
    return _rootIndex;
}

template<class DT>
int ArrayBST<DT>::maxSize() // max size of the tree
{
    return _size;
}

template<class DT>
void ArrayBST<DT>::setData(int index, DT &value) // set the DT to the tree index
{
    // index is position in vector
    _tree[index].setInfo(value);
}

template<class DT>
void ArrayBST<DT>::setLeft(int index, int value) // sets the tree index to the left value
{
    _tree[index].setLeft(value);
}

template<class DT>
void ArrayBST<DT>::setRight(int index, int value) // sets the tree index to the right value
{
    _tree[index].setRight(value);
}

template<class DT>
ostream& operator<<(ostream &os, const ArrayBST<DT> &x) // overloading the ostream operator
{
    x.display(os);  // using ostream in the display
    return os;
}

template<class DT>
void ArrayBST<DT>::display(ostream &os)  // display
{
    // just display
    displayPreOrder(os);    // sending ostream to pre and in displays
    displayInOrder(os);
}

template<class DT>
void ArrayBST<DT>::displayPreOrder(ostream &os) // display pre order
{
    // pre order: root, left, right
    os << "Pre Order Traversal: " << endl;

    // Adi 11/21/22
    // indirect recursion
    // second method: have an arguent(position of node), traversing 
    // sending index of node to second method
    // call _inorder(index)
    // preorder: printinfo()

    // diplayPreOrder()
    //  _preorder(_rootIndex)

    //_preorder(int pos)
    //  cout << _tree[pos].getInfo()
    //  checking if left and right not -1
    //  _preorder(_tree[pos].getleft())
    // _preorder(_tree[pos].getright())

    // inorder, swap cout and recursion 

    _preorder(_rootIndex);  // sending the root index to a recursive method

}

template<class DT>
void ArrayBST<DT>::_preorder(int pos)
{
    cout << *_tree[pos].getinfo() << " ";   // printing out each root during the recursive call

    if(_tree[pos].getleft() != -1)  // if there is a left subtree, go here first
    {
        _preorder(_tree[pos].getleft());
    }
    if(_tree[pos].getright() != -1) // if theres no more lefts, go right
    {
        _preorder(_tree[pos].getright());
    }

}

template<class DT>
void ArrayBST<DT>::displayInOrder(ostream &os)  // display in order
{
    // in order: left, root, right
    os << endl << "In Order Traversal: " << endl;
    
    _inorder(_rootIndex);   // passes the root index over to recursive method 

    os << endl;
}

template<class DT>
void ArrayBST<DT>::_inorder(int pos)
{
    if(_tree[pos].getleft() != -1)  // if left is there, go there to bottom left first
    {
        _inorder(_tree[pos].getleft());
    }
    cout << *_tree[pos].getinfo() << " ";   // prints out the root
    if(_tree[pos].getright() != -1) // goes right last if its available
    {
        _inorder(_tree[pos].getright());
    }
}

template<class DT>
void ArrayBST<DT>::printRaw() // print raw
{
    cout << endl << "Raw Data: " << endl;
    for (int i = 0; i < _size; i++) // loops through the size of the tree
    {
        if(_tree[i].getinfo() == nullptr)   // if the info is null, then skip it
        {
            continue;
        }
        else
        {
            cout << "Index " << i << ": "; // uses i instead of findIndex because findIndex wasnt working
            _tree[i].display(); // passes the tree to display in BTNode
        }
    }

    stack<int> tempLocations = _freeLocations;  // making temp stack so not popping the original stack
    cout << "Free Indexes: " << endl;
    if(tempLocations.size() == 0)   // output when the stack is empty
    {
        cout << "None";
    }

    while(tempLocations.size() != 0)    // loops through stack and prints out the locations
    {
        if(tempLocations.top() == 0)    // needed to make a case for 0 to avoid printing comma
        {
            cout << tempLocations.top();
            tempLocations.pop();
        }
        else
        {
            cout << tempLocations.top() << ", ";    // output for locations in stack
            tempLocations.pop();
        }
    }
    cout << endl;
    
}

template<class DT>
void ArrayBST<DT>::insert(DT &object) // insert
{
    // Adi 11/18/22
    // 1. check size in numNodes for output file 
    // 2. get spot from stack -> int freeLoc = _freeLocations.top(), then _freeLocations.pop()
    // 3. increment numNodes
    // 4. _tree[freeLoc].setInfo(obj);  // inserting root node
    // 5. current index = _rootIndex
    // 6. if(_rootIndex != freeLoc)
    // 7. while loop while(true)
    // 8. now to traverse the tree
    // 9. if{ if { else { }}}
    // 10. else{ if { else{ }}}
    // 11. first if in 9. -> if(_tree[currentIndex] > _tree[freeIndex]) //  moves left
    // 12. second if(_left == -1)
    // 13. current index. setLfeft.(freeIndex) break
    // 14. else currentIndex = _tree[currentIndex].getLeft();
    // 15. go right side in else in 10. 
    // 16. and thats it 
    
    if(_numNodes < _size)
    {
        int freeLoc = _freeLocations.top();   // gets the last index of the stack
        _freeLocations.pop();   // removes it
        _numNodes++;

        _tree[freeLoc].setInfo(object);   // sets the first root of the tree

        int currentIndex = _rootIndex;
        if(freeLoc != _rootIndex) // makes sure the indexes dont overlap and cause an issue
        {
            while(true)
            {
                if(_tree[currentIndex] > _tree[freeLoc])  // checks if the tree needs to go left or right
                {
                    if(_tree[currentIndex].getleft() == -1) // if there is no left node, set it here
                    {
                        _tree[currentIndex].setLeft(freeLoc);
                        break;
                    }
                    else
                    {
                        currentIndex = _tree[currentIndex].getleft();   // update the index if there is a left node
                    }
                }
                else
                {
                    if(_tree[currentIndex].getright() == -1)    // going right
                    {
                        _tree[currentIndex].setRight(freeLoc);
                        break;
                    }
                    else
                    {
                        currentIndex = _tree[currentIndex].getright();
                    }
                }
            }
        }
    }
    else
    {   
        cout << "Cannot insert data, BST Full." << endl;    // when the tree reaches its limit of nodes
    }

}

template<class DT>
bool ArrayBST<DT>::find(DT& object) // Sridhar gave us this
{
    return _find(object, _rootIndex);   // sends object to recursive method
}

template<class DT>
bool ArrayBST<DT>::_find(DT &object, int pos) // Sridhar gave us this
{
    if(*(_tree[pos].getinfo()) == object)   // if the object at the index is true
    {
        return true;
    }
    if(*(_tree[pos].getinfo()) < object)    // goes right if info is less than the object
    {
        if((_tree[pos].getright()) != -1)   // checks to make sure its not -1
        {
            return _find(object, _tree[pos].getright());
        }
        return false;
    }
    else
    {
        if((_tree[pos].getleft()) != -1)    // goes left instead
        {
            return _find(object, _tree[pos].getleft());
        }
        return false;
    }
}

template<class DT>
int ArrayBST<DT>::findIndex(DT &object) // find index
{
    int index = _rootIndex;
    while (index != -1)
    {
        if (*(_tree[index].getinfo()) == object)    // getting the index when it finds the object
        {
            return index;
        }
        if (*(_tree[index].getinfo()) < object) // traverses the tree right
        {
            index = _tree[index].getright();
        }
        else
        {
            index = _tree[index].getleft(); // sends the tree left
        }
    }

    return -1;
}

template<class DT>
void ArrayBST<DT>::remove(DT &object) // remove
{
    // find the node
    // reconnect children 
    // put back index position 
    
}

////////////////////////////////////////////////////////////////////////////////////////
// Main Method
////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Get input for the size of the tree
	int inputSize;
	cin >> inputSize;

    cout << "Number of maximum nodes: " << inputSize << endl;

	// Create a BST of the size inputSize
	ArrayBST<int> myBST = ArrayBST<int>(inputSize);

    // TODO: input loop for commands
    char command;
    int value;  // for the given input

    while(cin >> command)
    {
        switch(command)
        {
            case 'I':   // Insert working
            {
                cin >> value;
                cout << endl << "Inserting " << value << endl;
                myBST.insert(value);    // calls the insert method
                break;
            }
            case 'O':   // output using ostream
            {
                // https://stackoverflow.com/questions/5507924/c-passing-ostream-as-parameter
                // trying this out for parameter of ostream

                cout << endl << "Information in Tree: " << endl;
                myBST.display(cout); // this will call the ostream operator

                break;
            }
            case 'A':   // output using displayRaw
            {
                myBST.printRaw();   // calls the printRaw method

                break;
            }
            case 'F':   // search working 
            {
                cin >> value; 
                cout << endl << "Finding " << value << endl;

                if(myBST.find(value))   // if it finds the value, it returns the index
                {
                    cout << "Number found at index " <<  myBST.findIndex(value) << "." << endl;
                }
                else
                {
                    cout << "Number not found." << endl;    // if its not in the tree
                }
              myBST.find(value);

              break;
            }
            case 'R':   // Remove
            {
                break;
            }
            default:
            {
                cout << "oh geez" << endl;
                break;
            }
        }
    }

	return 0;
}