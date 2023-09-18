/*
Visit the root.
Traverse the left subtree, call Preorder(left->subtree)
Traverse the right subtree, call Preorder(right->subtree)
*/


#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;

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

//+ab
void PreOrderTraversal(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        {return;}


    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
    
}


int main()
{
    BinaryTreeNode<int>* root = Take_level_input();
    PreOrderTraversal(root);

}
