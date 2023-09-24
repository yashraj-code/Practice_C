// Checking if a binary tree is a perfect binary tree in C++

/*
A perfect binary tree is a type of binary tree in which
    - every internal node has exactly two child nodes and
    - all the leaf nodes are at the same level.
*/

#include <iostream>
using namespace std;

class Node 
{
	public:
		int data;
		Node* right;
		Node* left;
	
	Node(int value)
	{
		data=value;
		right= NULL;
		left = NULL;
	}
};

int depth(Node *node) 
{
  int d = 0;
  while (node != NULL) 
  {
    d++;
    node = node->left;
  }
  return d;
}

bool isPerfectR(Node *root, int d, int level = 0) 
{
  if (root == NULL)
    return true;

  if (root->left == NULL && root->right == NULL)
    return (d == level + 1);

  if (root->left == NULL || root->right == NULL)
    return false;

  return isPerfectR(root->left, d, level + 1) &&
       isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Node *root) 
{
  int d = depth(root);
  return isPerfectR(root, d);
}


int main() 
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);

  if (isPerfect(root))
    cout << "The tree is a perfect binary tree\n";
  else
    cout << "The tree is not a perfect binary tree\n";
}