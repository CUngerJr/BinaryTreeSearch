// Header File for BST

#include <iostream>
#include <iomanip>

#ifndef BST
#define BST

class BT
{
private:
	struct node
	{
		char data;
		node* left;
		node* right;
	};
	node* root; 
	bool found;
	struct node;
	int nEndNodeCount;		// HELPER TO HOLD LEAF COUNT INTEGER
public:
	BT();			//Constructor
	bool isEmpty() const { return root == NULL; }		//Check for empty
	void insert(char);									//Insert item in BST
	void preorder();									//Preorder traversing driver
	void preorderTrav(node*);							//Preorder traversing
	void Delete(char);									//Delete a Node
	bool Search(char);									//Perform a Search
	void LeafCount(node*);								//Counts number of leaves in BST
	int getLeafCount() { return nEndNodeCount; }		// Helper to return integer of leaf nodes
	bool Siblings(char);								// Finds siblings of a node
};

#endif // !BST


