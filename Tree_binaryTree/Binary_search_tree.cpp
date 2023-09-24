// Binary Search Tree operations in C++

/*
- All nodes of left subtree are less than the root node
- All nodes of right subtree are more than the root node
*/

// For node having 1 Child 
/*
Copy the child to the node and delete the node.
1. Replace that node with its child node.
2. Remove the child node from its original position.
*/

// FOR node having 2 child
/*
1. Get the inorder successor of that node to be deleted.
2. Replace the node with the inorder successor.
3. Remove the inorder successor from its original position.
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


// Inorder Traversal
void inorder(Node *root) 
{
  if (root != NULL) 
  {
    inorder(root->left);
    cout << root->data << " -> ";
    inorder(root->right);
  }
}

// Insert a node
Node *insert(Node *node, int key) 
{
  // Return a new node if the tree is empty
  if (node == NULL) 
  	return (new Node(key));

  // Traverse to the right place and insert the node
  if (key < node->data)
    {node->left = insert(node->left, key);}

  else
    {node->right = insert(node->right, key);}

  return node;
}

// Find the inorder successor
Node *minValueNode(Node *node) 
{
  Node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    {current = current->left;}

  return current;
}

// Deleting a node
Node *deleteNode(Node *root, int data) 
{
  // Return if the tree is empty
  if (root == NULL) 
  	{return root;}

  // Find the node to be deleted
  if (data < root->data)
    {root->left = deleteNode(root->left, data);}

  else if (data > root->data)
    {root->right = deleteNode(root->right, data);}
  
  else 
  {
    // If the node is with only one child or no child
    if (root->left == NULL) 
	{
      Node *temp = root->right;
      free(root);
      return temp;
    } 
	else if (root->right == NULL) 
	{
      Node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    Node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->data = temp->data;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

// Driver code
int main() {
  Node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  cout << "Inorder traversal: ";
  inorder(root);

  cout << "\nAfter deleting 10\n";
  root = deleteNode(root, 10);
  cout << "Inorder traversal: ";
  inorder(root);
}