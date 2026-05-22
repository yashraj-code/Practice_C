/*
The left subtree of a node contains only nodes with keys less than the node’s key.
The right subtree of a node contains only nodes with keys greater than the node’s key.
*/

/*
for each node, check if max value in left subtree is smaller than the node and 
min value in right subtree greater than the node. 
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

int minValue(Node* root)
{
    if(root==NULL)
        {return INT16_MIN;}
    
    int value = root->data;
    int left_min = minValue(root->left);
    int right_min = minValue(root->right);

    return(min(value,min(left_min, right_min)));
}

int maxValue(Node* root)
{
    if(root==NULL)
        {return INT16_MAX;}
    
    int value = root->data;
    int left_max = maxValue(root->left);
    int right_max = maxValue(root->right);

    return(max(value,max(left_max,right_max)));
}

int isBST(Node* root)
{
    if(root==NULL)
        {return 1;}
    
    // left side should contain value less than root
    // so left side max should be less than root will full fill the situatioin
    if(root->left !=NULL && maxValue(root->left)>=root->data)
    {
        // it doesn't satisfy the condition so return false;
        return 0;
    }

    if(root->right !=NULL && minValue(root->right)<=root->data)
    {
        // it doesn't satisfy the condition so return false;
        return 0;
    }

    // right and left both should be BST
    if(!isBST(root->left) || !isBST(root->right))
        {return 0;}

    
    // if everything is good 
    return 1;
}
