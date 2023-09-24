// Checking if a binary tree is a full binary tree in C++

/*
- A perfect binary tree is a type of binary tree in which
    - every internal node has exactly two child nodes and
    - all the leaf nodes are at the same level.
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
		right=NULL;
		left=NULL;
	}
};


bool isFullBinaryTree(Node *root)
{
  
  // Checking for emptiness
  if (root == NULL)
    return true;

  // Checking for the presence of children
  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  return false;
}

int main() 
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);

  if (isFullBinaryTree(root))
    cout << "The tree is a full binary tree\n";
  else
    cout << "The tree is not a full binary tree\n";
}