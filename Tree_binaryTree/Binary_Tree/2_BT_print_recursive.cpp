/*
output should be 
1: L2, R3
2:
3:
*/

#include<stdio.h>
#include<iostream>
#include "BinaryTreeNode.h"

using namespace std;

void PrintTree(BinaryTreeNode<int> * root)
{
    //base case
    if(root==NULL)
        {return;}
    
    cout<<root->data<<":";

    // Could have printed in sstraight line with this 
    // cout<<root->data<<endl;
    // PrintTree(root->left);
    // PrintTree(root->right);

    //Suppose after one level tree has only left nodes
    //For that we used if here, so that right doesn't run
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
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> * node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> * node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;
    PrintTree(root);
    delete(root);
}