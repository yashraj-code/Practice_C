/*
We will take input and ask everytime about left, right, 
when user does not want to have child (-1) is expected there. 

               1
            /     \
           2       3
          / \     /  \
        -1  -1  -1   -1

input would be -> 1 2 -1 -1 3 -1 -1 
*/


#include<stdio.h>
#include<iostream>
#include "BinaryTreeNode.h"

using namespace std;


 BinaryTreeNode<int>* takeInput()
 {
    int rootData;
    cout<<"\nEnter Data ";
    cin>>rootData;

    //base case
    // dont call any further return
    if(rootData== -1)
    {return NULL;}

    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> * leftchild = takeInput();
    BinaryTreeNode<int> * rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;

    return root;

 }


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

int main()
{
    BinaryTreeNode<int> * root = takeInput();
    PrintTree(root);
}