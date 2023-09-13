/*
PRINT LEVEL WISE

Again we will use concept of Queue

               1
            /     \
           2       3
          / \     /  \
        4    5   6    7

input would be -> 1 2 3 4 5 6 7

OUTPUT -
1: L2 R3
2: L4 R5
3: L6 R7
4:
5: 
6:
7:
*/


#include<stdio.h>
#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"

using namespace std;



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
        else
            {cout<<" L"<<-1;}

        if(frontNode->right!=NULL)
            {
                cout<<" R"<<frontNode->right->data;
                nodes_queue.push(frontNode->right);
            }
        else
            {cout<<" R"<<-1;}
    cout<<endl;

    }
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
    Print_level_Tree(root);
}