/*
Given two Generic trees, return true if they are structurally identical 
i.e. they are made of nodes with the same values arranged in the same way.
*/

#include<iostream>
#include<bits/stdc++.h>  
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;

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

bool isSameTree(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) 
    {
        if(p==NULL || q==NULL)
        {
            if(p==NULL && q==NULL)
                {return true;}
            else
                {return false;}
        }


        if(p->data == q->data)
        {
            // move to left and right
            return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
        }
        else
            {return false;}

    }

int main()
{
    BinaryTreeNode<int>* root1 = Take_level_input();
    BinaryTreeNode<int>* root2 = Take_level_input();

    if(isSameTree(root1,root2)==true)
        {cout<<"True";}
    else
        {cout<<"False";}
}