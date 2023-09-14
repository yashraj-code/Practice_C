/*
Given a binary tree, find and return the height of given tree.
*/

/*
See always we will imagine root, leftsubtree, right subtree

now we should expect that we have height from subtree and right subtree
Now we pick max in both of the subbtrees, and we add our root(+1)
and return
*/

#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;

int height(BinaryTreeNode<int> * root)
{
    //base case
    if(root==NULL){return 0;}

    int left_height = height(root->left);
    int right_height = height(root->right);

    //pickup max from both
    return max(left_height,right_height)+1;
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
    cout<<"\nHeight = "<<height(root)<<endl;
}