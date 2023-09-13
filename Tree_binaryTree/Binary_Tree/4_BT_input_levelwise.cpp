/*
We will take input level wise
Again we will use concept of Queue

               1
            /     \
           2       3
          / \     /  \
        4    5   6    7

input would be -> 1 2 3 4 5 6 7
*/


#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;

void PrintTree(BinaryTreeNode<int> * root)
{
    //base case
    if(root==NULL)
        {return;}
    
    cout<<root->data<<":";

    if(root->left !=NULL)
        {cout<<" L"<<root->left->data;}

    if(root->right !=NULL)
        {cout<<" R"<<root->right->data;}
    
    cout<<endl;
    PrintTree(root->left);
    PrintTree(root->right);
}


BinaryTreeNode<int> * Take_level_input()
{
    int rootData;
    cout<<"Enter Root Data ->" <<endl;
    cin>>rootData;

    //Not required
    //Just for backup
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
        cout<<"\nEnter Left Child of "<<front->data<<" ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        //For RIGHT CHILD
        cout<<"\nEnter right Child of "<<front->data<<" ";
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

int main()
{
    BinaryTreeNode<int>* root = Take_level_input();
    PrintTree(root);
}