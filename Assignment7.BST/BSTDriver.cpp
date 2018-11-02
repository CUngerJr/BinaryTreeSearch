/*	Christopher Unger
CSC - 220
Assignment 7 -	Binary Search Tree
Purpose:	Program will Insert Nodes, Conduct a Traversal PreOrder, Search BST, Delete Nodes,
display a Leaf Count, display Sibling(s) of Nodes, and Quit Option*/

#include <iostream>
#include <iomanip>
using namespace std;

#include "BTS.h"

int main()
{
	BT b;
	int ch, num;
	char tmp, searchN, item, sib;

	system("cls");
	cout << "-----------Menu-------------" << endl;
	cout << endl;
	cout << "1. Insert node(s) in BST" << endl;
	cout << "2. Pre-order Traversal" << endl;
	cout << "3. Search BST" << endl;
	cout << "4. Delete Node in BST" << endl;
	cout << "5. Perform Leaf Count" << endl;
	cout << "6. Find Siblings of a Node" << endl;
	cout << "7. Quit" << endl << endl;

	do
	{
		cout << endl << "Enter Your Choice <1..7> ?";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter number of nodes to insert: ";
			cin >> num;
			for (int i = 0; i<num; i++)
			{
				cout << endl;
				cout << "Enter node: ";
				cin >> tmp;
				b.insert(tmp);
			}
			break;

		case 2:
			cout << endl;
			cout << "Pre-Order Traversal" << endl;
			cout << endl << "Node Info" << setw(16) << "Left Child" << setw(16) << "Right Child" << endl;
			b.preorder();		//call to Preorder traversing driver
			break;

		case 3:
			cout << endl;
			cout << "Search BST" << endl;
			cout << "Enter Node to Search: ";
			cin >> searchN;
			b.Search(searchN);	// CALL SEARCH NODE
			break;

			case 4:
			cout << endl;
			cout << "Delete Node in BST" << endl;
			cout << "Enter Node to Delete: ";
			cin >> item;
			b.Delete(item);		// CALL DELETE A NODE
			break;

		case 5:
			b.LeafCount(NULL);				// CALL FOR LEAF COUNT
			cout << endl;
			cout << "Leaf Count" << endl;
			cout << "There are " << b.getLeafCount() << " leaves in the BST!" << endl;  // RETURN LEAF COUNT
			break;

		case 6:
			cout << endl;
			cout << "Siblings Info" << endl;
			cout << "Enter node to check for sibling: ";
			cin >> sib;
			b.Siblings(sib);			// CALL FIND CHECK FOR SIBLINGS
			break;

		case 7:
			cout << endl << "Good-Bye!" << endl << endl;
			return 0;
			//break;

		case 8:
		default:
			cout << endl << "Invalid Data Entry" << endl;
		}
	} while (ch != 7);

	system("pause");
	return 0;
}