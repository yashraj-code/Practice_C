/*
Height of Binary Tree
Complexity - O(n)
As we are visiting each and every node
*/

/*
              1             - 2
             / \
            2   3           - 1
           / \  / \         
          4   5 6  7        - 0
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

    cout<<"Height of Binary tree is ";
    cout<<heightOfTree(root);
}
