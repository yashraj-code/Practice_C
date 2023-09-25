// C++ program to check if a given binary tree is complete or not
// Solution 2

// A node is ‘Full Node’ if both left and right children are not empty (or not NULL).

/*
 Check whether the NULL Node encountered is the last node of the Binary Tree. 
 If the null node encountered in the binary tree is the last node then it is a complete binary tree 
 and if there exists a valid node even after encountering a null node then the tree is not a complete binary tree.
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

/* Given a binary tree, return true if the tree is complete else false */
bool isCompleteBT(node* root)
{
    
// Create an empty queue
    queue<node*> q;
    q.push(root);

    // Create a flag variable which will be set true when a non null node is seen
    bool flag = false;
 
    // Do level order traversal using queue.
    while (!q.empty()) 
	{
        node* temp = q.front();
        q.pop();
 
        if (temp == NULL) 
		{
            // If we have seen a NULL node, we set the flag to true
            flag = true;
        }
        else 
		{
            // If that NULL node is not the last node then
            // return false
            if (flag == true) 
				{return false;}

            // Push both nodes even if there are null
            q.push(temp->left);
            q.push(temp->right);
        }
    }
 
    // If we reach here, then the tree is complete Binary Tree
    return true;
}

/* Driver code*/
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
