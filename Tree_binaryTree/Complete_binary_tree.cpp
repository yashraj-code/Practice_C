// Checking if a binary tree is a complete binary tree in C++
//solution_3 (Recursive)

/*
A complete binary tree is a binary tree in which all the levels are completely filled 
except possibly the lowest one, which is filled from the left.
*/

/*
In the array representation of a binary tree, 
if the parent node is assigned an index of ‘i’ and 
left child gets assigned an index of ‘2*i + 1’ while 
the right child is assigned an index of ‘2*i + 2’. 

If we represent the above binary tree as an array with the respective indices 
assigned to the different nodes of the tree above from top to down and left to right.

    Hence we proceed in the following manner in order to check if the binary tree is complete binary tree. 

    1. Calculate the number of nodes (count) in the binary tree.
    2. Start recursion of the binary tree from the root node of the binary tree with index (i) being set as 0 
		and the number of nodes in the binary (count).
    3. If the current node under examination is NULL, then the tree is a complete binary tree. Return true.
    4. If index (i) of the current node is greater than or equal to the number of nodes in the binary tree (count) 
		i.e. (i>= count), then the tree is not a complete binary. Return false.
    5. Recursively check the left and right sub-trees of the binary tree for same condition. 
		For the left sub-tree use the index as (2*i + 1) while 
		for the right sub-tree use the index as (2*i + 2).

*/



#include <iostream>

using namespace std;

class Node 
{
	public:
		int data;
		Node* left;
		Node* right;

	Node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

// Count the number of nodes
int countNumNodes(Node *root) 
{
  if (root == NULL)
    return (0);
	
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is a complete binary tree
bool checkComplete(Node *root, int index, int numberNodes) {
  
  // Check if the tree is empty
  if (root == NULL)
    return true;

  if (index >= numberNodes)
    return false;

  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main() 
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);

	int node_count = countNumNodes(root);
	int index = 0;

	if (checkComplete(root, index, node_count))
		cout << "The tree is a complete binary tree\n";
	else
		cout << "The tree is not a complete binary tree\n";
}
