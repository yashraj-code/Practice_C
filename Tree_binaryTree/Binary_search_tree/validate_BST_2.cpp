/*
The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
*/

/*
// range of minimum and maximum values of nodes

 checks whether a subtree (rooted at a given node) is a BST within the specified range of minimum (min) and maximum (max) values.
 If any node violates this range, the function returns false; 
 otherwise, it continues checking the left and right subtrees.
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

bool isBSTUtil(Node* root, int min, int max)
{
    // if there is nothing then return true
    if(root==NULL)
        {return true;}

    int value = root->data;
    
    // node should lie in between min and max
    if(value< min || value >max)
        {return false;}
    
    // do it for both part of the tree

    // left side ->smaller so -> (min,node->value-1)
    // right side -> larger so ->(node->value+1, max)
    return isBSTUtil(root->left,min,value-1)
            &&
            isBSTUtil(root->right,value+1,max);

}

bool isBST(Node* root)
{
    return (isBSTUtil(root,INT16_MIN,INT16_MAX));
}


int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

 if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
 
    return 0;
}