/*
Traverse the left subtree, call Postorder(left->subtree)
Traverse the right subtree, call Postorder(right->subtree)
Visit the root.
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


void PostOrderTraversal(Node* root)
{
    if(root==NULL)
        {return;}
    
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
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

    cout<<"Postorder traversal of Binary tree is \n";
    PostOrderTraversal(root);

}
