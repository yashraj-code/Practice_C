/*
Visit the root.
Traverse the left subtree, call Preorder(left->subtree)
Traverse the right subtree, call Preorder(right->subtree)
*/

/*
              1
             / \
            2   3
           / \  / \
          4   5 6  7
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


void PreOrderTraversal(Node* root)
{
    if(root==NULL)
        {return;}


    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    
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

    cout<<"Preorder traversal of Binary tree is \n";
    PreOrderTraversal(root);

}
