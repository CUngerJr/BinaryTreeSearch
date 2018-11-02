// BST Member Definition

#include <iostream>
#include <iomanip>
using namespace std;

#include "BTS.h"

//Constructor
BT::BT()
{
	root = NULL;
}

//Insert new in BST
void BT::insert(char d)
{
	node* t = new node;
	node* parent;

	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	if (isEmpty())
		root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}
		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

//Function - Preorder travesing driver
void BT::preorder()
{
	preorderTrav(root);
}
//Function - Preorder travesing
void BT::preorderTrav(node* p)
{

		while (p != NULL)
		{
			cout << setw(6) << p->data;						// DISPLAY NODE

			if (p->left != NULL)							// CHECK FOR LEFT CHILD
			{
				cout << setw(14) << p->left->data;			
			}
			else
			{
				cout << setw(15) << "NIL";
			}
			if (p->right != NULL)							// CHECK FOR RIGHT CHILD
			{
				cout << setw(16) << p->right->data << endl;
			}
			else
			{
				cout << setw(16) << "NIL" << endl;
			}

			preorderTrav(p->left);							// RECURS LEFT
			preorderTrav(p->right);							// RECURS RIGHT
			return;
		}

}
	
// Function - Binary Search
bool BT::Search(char searchN)
{
	bool found = false;
	node *temp = root;

	while (!found && temp != NULL)
	{
		if (searchN < temp->data)			// GO LEFT
		{
			temp = temp->left;
		}
		else if (searchN > temp->data)		// GO RIGHT
		{
			temp = temp->right;
		}
		else
		{
			found = true;
			cout << endl << "Node Info" << setw(16) << "Left Child" << setw(16) << "Right Child" << endl;
			cout << setw(6) << temp->data;										// PRINT NODE

			if (temp->left != NULL)												// CHECK FOR LEFT CHILD
			{
				cout << setw(14) << temp->left->data;
			}
			else
			{
				cout << setw(15) << "NIL";
			}
			if (temp->right != NULL)												// CHECK FOR RIGHT CHILD
			{
				cout << setw(16) << temp->right->data << endl;
			}
			else
			{
				cout << setw(16) << "NIL" << endl;
			}
		}
	}
	if (!found)
	{
		cout << endl << "NODE " << '"' << searchN << '"' << " IS NOT FOUND IN THE BST!" << endl;				// NODE NOT FOUND IN BST
	}
	return found;
}

// FUNCTION DELETE NODE WIITH 3 OPTIONS
void BT::Delete(char item)
{
	node *x = root;
	node *parent = 0;
	found = false;

	while (!found && x != 0)			// SEARCH FOR NODE
	{
		if (item < x->data)		// GO LEFT
		{
			parent = x;
			x = x->left;
		}
		else if (x->data < item)  // GO RIGHT
		{
			parent = x;
			x = x->right;
		}
		else
		{
			found = true;
		}
	}

	if (!found)
	{
		cout << "The Node " << item << " is NOT IN THE BST!" << endl;		// NODE NOT FOUND IN BST
		return;
	}
	else
	{
		if (x->left && x->right == NULL)				// NO CHILDREN -> DELETE NODE
		{
			delete x;
			return;
		}
		if (x->left != NULL && x->right != NULL)		// DELETE NODE WITH 2 CHILDREN
		{
			node*xSucc = x->right;
			parent = x;

			while (xSucc->left != NULL)
			{
				parent = xSucc;
				xSucc = xSucc->left;
			}
			
			x->data = xSucc->data;
			x = xSucc;
		}
	}
	
	node*subtree = x->left;						// DELETE NODE WITH 0 OR 1 CHILDREN

	if (subtree == NULL)
	{
		subtree = x->right;
	}
	if (parent == NULL)
	{
		root = subtree;
	}
	else if (parent->left == x)
	{
		parent->left = subtree;
	}
	else
	{
		parent->right = subtree;
		delete x;
	}
}	

// LEAF COUNT FUNCTION
void BT::LeafCount(node*pCurNode)
{
	if (pCurNode == NULL) 
	{
		pCurNode = root;
		nEndNodeCount = 0;						// INITIALIZE COUNTER
	}

	if (!pCurNode->left && !pCurNode->right)	// IF LEAF, ADD TO COUNTER
	{
		nEndNodeCount++;
	}
	else
	{
		if (pCurNode->left != NULL)		// RECURSE LEFT
			LeafCount(pCurNode->left);
		if (pCurNode->right != NULL)	// RECURSE RIGHT
			LeafCount(pCurNode->right);
	}
}

// SIBLING FUNCTION
bool BT::Siblings(char sib)
{
	node *p = root;
	bool found = false;

	while (p != NULL)
	{
		while (!found && p->data != NULL)
		{
			if (sib < p->data)				// SEARCH LEFT SUBTREE
			{
				if (p->data != sib && p->left == NULL && p->right == NULL)			// NODE NOT FOUND IN BST
				{
					cout << "The node " << sib << " is NOT IN THE BST!" << endl;
					return found;
				}
				if (p->left->data == sib && p->right != NULL)				// NODE FOUND IN LEFT SUBTREE & SIBLING FOUND
				{
					found = true;
					cout << endl << "The sibling of " << sib << " is " << p->right->data << "." << endl;
					return found;
				}
				else                         // NODE NOT FOUND YET IN LEFT SUBTREE
				{
					p = p->left;				// GO LEFT
				}
			}
			if (sib > p->data)					// SEARCH RIGHT SUBTREE IF NODE GREATER THAN ROOT
			{
				if (p->data != sib && p->right == NULL && p->left == NULL)					// NODE NOT FOUND IN BST
				{
					cout << "The node " << sib << " is NOT IN THE BST!" << endl;
					return found;
				}
				if (p->right->data == sib && p->left != NULL)					// NODE FOUND IN RIGHT SUBTREE & SIBLING FOUND
				{
					found = true;
					cout << endl << "The sibling of " << sib << " is " << p->left->data << "." << endl;
					return found;
				}
				else                        // NODE NOT FOUND YET IN RIGHT SUBTREE
				{
					p = p->right;			// GO RIGHT
				}
			}
			if (sib == p->data)				// NODE IS FOUND, BUT HAS NO SIBLINGS
			{
				found = true;
				cout << endl << "The Node " << sib << " has NO SIBLINGS!" << endl;
				return found;
			}
		}
	}
	return found;
}



