/*
Mirror the given binary tree. 
That is, right child of every nodes should become left and left should become right.

            1                   1
           / \                 / \
         2     3             3     2
        / \   / \           / \   / \
      4    5 6   7         7   6 5   4    

*/

/*
approach - just swap the values and use recursion
*/

#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;

void mirror(BinaryTreeNode<int> * root)
{
    if(root==NULL)
    {return ;}

    BinaryTreeNode<int>* temp;
    temp=root->left;
    root->left = root->right ;
    root->right =temp;

    mirror(root->left);
    mirror(root->right);
}

BinaryTreeNode<int> * Take_level_input()
{
    int rootData;
    cout<<"Enter Root Data ->" <<endl;
    cin>>rootData;

    if(rootData == -1)
    {return NULL;}

    //create node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    //create a queue
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size()!=0)
    {
        //pop out the first element
        BinaryTreeNode<int>* front =pendingNodes.front();
        pendingNodes.pop();
        
        //For LEFT CHILD
        cout<<"\nEnter Left Child of "<<front->data<<"-> ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        //For RIGHT CHILD
        cout<<"\nEnter right Child of "<<front->data<<"-> ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }

    return root;
}

void Print_level_Tree(BinaryTreeNode<int> * root)
{
    //base case
    if(root==NULL)
        {return;}
    
    // make a queue for levels
    queue<BinaryTreeNode<int>*> nodes_queue;

    nodes_queue.push(root);
    while(nodes_queue.size()!=0)
    {
        BinaryTreeNode<int>* frontNode = nodes_queue.front();
        nodes_queue.pop();

        cout<<frontNode->data<<" : ";

        if(frontNode->left!=NULL)
            {
                cout<<" L"<<frontNode->left->data;
                nodes_queue.push(frontNode->left);
            }

        if(frontNode->right!=NULL)
            {
                cout<<" R"<<frontNode->right->data;
                nodes_queue.push(frontNode->right);
            }

    cout<<endl;
    }
}


int main()
{
    BinaryTreeNode<int>* root = Take_level_input();
    mirror(root);
    Print_level_Tree(root);
}