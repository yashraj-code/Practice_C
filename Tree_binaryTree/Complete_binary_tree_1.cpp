// C++ program to check if a given binary tree is complete or not
// Solution 1

// A node is ‘Full Node’ if both left and right children are not empty (or not NULL).

/*
The approach is to do a level order traversal starting from the root.
In the traversal, once a node is found which is NOT a Full Node, all the following nodes must be leaf nodes.
															(condition for complete tree is no extra level)

Also, one more thing needs to be checked to handle the below case: 
	If a node has an empty left child, then the right child must be empty.
*/


#include <bits/stdc++.h>
using namespace std;

class node 
{
	public:
		int data;
		node* left;
		node* right;
	node(int val)
	{
		data=val;
		left=NULL;
		right=NULL;
	}
};

// Given a binary tree, return true if the tree is complete else false
bool isCompleteBT(node* root)
{
	queue<node*> q;
	q.push(root);

	// Create a flag variable which will be set true when a non null node is seen
	bool flag = false;

	// Do level order traversal using queue.
	while (!q.empty()) 
	{
		node* temp = q.front();
		q.pop();

		/* Check if left child is present*/
		if (temp->left) 
		{
			// If we have seen a non full node, and we see a
			// node with non-empty left child, then the
			// given tree is not a complete Binary Tree
			if (flag == true)
				return false;

			q.push(temp->left); // Enqueue Left Child
		}
		// If this a non-full node, set the flag as true
		else
			flag = true;

		// Check if right child is present
		if (temp->right) {
			// If we have seen a non full node, and we see a
			// node with non-empty right child, then the
			// given tree is not a complete Binary Tree
			if (flag == true)
				return false;

			q.push(temp->right); // Enqueue Right Child
		}
		// If this a non-full node, set the flag as true
		else
			flag = true;
	}

	// If we reach here, then the tree is complete Binary Tree
	return true;
}

int main()
{
	/* Let us construct the following Binary Tree which
		is not a complete Binary Tree
			1
			/ \
			2 3
		/ \ \
		4 5 6
		*/

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);

	if (isCompleteBT(root) == true)
		cout << "Complete Binary Tree";
	else
		cout << "NOT Complete Binary Tree";

	return 0;
}
