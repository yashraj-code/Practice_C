/*
    the diameter of T’s left subtree.
    the diameter of T’s right subtree.
    the longest path between leaves that goes through the root of T 
    (this can be computed from the heights of the subtrees of T) 
        - for this we are calculating height and doing everything
*/

#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* right;
        Node* left;

    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};

int heightOfTree(Node* root)
{
    if(root==NULL){return 0;}

    int left_height = heightOfTree(root->left);
    int right_height = heightOfTree(root->right);

    return max(left_height,right_height)+1;
}

int DiameterOfTree(Node* root)
{
    if(root==NULL){return 0;}
    
    int left_height = heightOfTree(root->left);
    int right_height = heightOfTree(root->right);
    int curr_diameter=left_height+right_height+1;

    int left_dia = DiameterOfTree(root->left);
    int right_dia = DiameterOfTree(root->right);

    return max(curr_diameter,max(left_dia,right_dia));

    // +1 so that we account for node that we are standing on
}


int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"Height of Binary tree is \n";
    cout<<heightOfTree(root);
}
