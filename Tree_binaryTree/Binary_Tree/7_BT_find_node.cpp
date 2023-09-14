/*
Given a Binary Tree and an integer x,
check if node with data x is present in the input binary tree or not.
Return true or false.


*/


#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;



bool find_node(BinaryTreeNode<int> * root, int value)
{
    if(root==NULL)
    {return false;}

    if(root->data==value)
        {return true;}

    if(find_node(root->left, value)==true || find_node(root->right, value)==true)
    {return true;}

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

int main()
{


    BinaryTreeNode<int>* root = Take_level_input();
    int value;
    cout<<"Value -> ";
    cin>>value;

    cout<<find_node(root,value)<<endl;
}