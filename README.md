# CompStructures_P5

# Objective
1. Use STL stack and vector in the project.
2. Implement ArrayBST class.
3. Implement main() that read and process the input according to the project description
– for each of I, F, O and A commands.

# Description
The main objective of this project is to store the binary search tree using an array data structure as presented below.

ArrayBST:
The binary search tree data structure can be stored using a number of ways including pointers (_left and _right tree pointers), 
with a single dimensional array (mainly used for storing a complete binary tree), and the array of left and right index (call this ArrayBST) approach. 
The ArrayBST is similar to the array implementation of a linked list discussed in the textbook.

In the ArrayBST, we will have an array (or vector) of ArrayBTNode objects. The size of the array or vector is K, which can be 
specified in the constructor with default value of lets say 20. The root of the binary tree is placed at an index position say x with a 
value of say 100. Let us also assume that the root node has a left child with a value of 50 and a right child with a value of 200. The left child 
(or the right child) can be at any index position of the array. Let these positions be y (left index) and z (right index), respectively. We have to 
store this information at the root node located at index position x.

The left child (resp. right child) of the root is at index position 2 (resp. 4). The left child of node with value 50 is at index position 3 
while its right child with a value of 60 is at index position 6. Positions 1 and 7 are empty slots (because _info is set to NULL) wherein new nodes 
can be placed. The algorithms to remove a node will place NULL at appropriate index positions. When the left (resp. right) index is a -1 then it 
implies that the left child of that node is empty.

Insertion and Removal
In order to insert a new node, first we need to find an index position with _info set to NULL. The time to complete this task in the 
worst case will be equal to the size of the vector. But a simple technique to keep track of the free positions is to use a stack. You can 
use the STL stack (call it freeLocations) for this purpose. When the BinarySearchTree is created you will initialize this stack with empty positions 
0 through maximum number of nodes minus one. That is, will push values 0, 1, 2, 3, ..., n-1, onto the stack where n is the maximum number of nodes 
allowed in the binary tree. So, you will have n – 1 as the first index position to store the first insertion node. Whenever you need to insert a 
node into the binary search tree you pop an index position from the stack. When a node is removed, we need to push the corresponding position onto 
the stack.

search
Search returns the index of the ArrayBTNode object in the vector. Sequential search cannot be used to implement search method. Binary Search is 
the way to go about this search.

ostream operator and DisplayRaw
The overloaded ostream operator should print both the preorder and inorder traversals. You will also implement a DisplayRaw method that 
prints out the following information stored in the data structure:
(a) Position, *_info, _left, _right in the array (only for the rows with data stored) 
(b) The content of the stack
