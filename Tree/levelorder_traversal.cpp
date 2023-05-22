/*
explanation in Notion 
*/

/*
              1             - 0
             / \
            2   3           - 1
           /   / \         
          4   5   6         - 2
              \   /
               7 8          - 3
*/

#include<iostream>
#include<queue>

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


void Levelorder(Node* root)
{
    if(root==NULL){return;}

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        if(node != NULL)
        {
            cout<<node->data<<" ";
            if(node->left){q.push(node->left);}
            if(node->right){q.push(node->right);}

        }
        else if (!q.empty())
            {q.push(NULL);}
    }
}


int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);

    root->right->left=new Node(5);
    root->right->left->right=new Node(7);


    root->right->right=new Node(6);
    root->right->right->left=new Node(8);

    cout<<"Level Order Traversal of Binary tree is \n";
    Levelorder(root);
}
