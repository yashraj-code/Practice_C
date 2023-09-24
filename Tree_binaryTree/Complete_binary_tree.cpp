// Checking if a binary tree is a complete binary tree in C++

/*
A complete binary tree is a binary tree in which all the levels are completely filled 
except possibly the lowest one, which is filled from the left.
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
