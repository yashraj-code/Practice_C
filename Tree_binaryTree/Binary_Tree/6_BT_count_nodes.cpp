#include<stdio.h>
#include "BinaryTreeNode.h"
#include<queue>
#include<iostream>

using namespace std;

int count_nodes(BinaryTreeNode<int>* root)
{
    //base case
    if(root==NULL)
    {return 0;}

    int total=1;
    total = total + count_nodes(root->left) + count_nodes(root->right);
    return total;

}

BinaryTreeNode<int>* levelWise_Input()
{
    cout<<"Enter root -> ";
    int rootData;
    cin>>rootData;

    //create it 
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    //create a queue
    queue<BinaryTreeNode<int>*> PendingNodes;
    PendingNodes.push(root);
    
    while (PendingNodes.size()!=0)
    {
        BinaryTreeNode<int>* frontnode = PendingNodes.front();
        PendingNodes.pop();

        //left side
        int leftData;
        cout<<"\nEnter Left Child of "<<frontnode->data<<" - ";
        cin>>leftData;
        if(leftData!=-1)
        {
        BinaryTreeNode<int>* leftchild= new BinaryTreeNode<int>(leftData);
        frontnode->left=leftchild;
        PendingNodes.push(leftchild);
        }

        int rightData;
        cout<<"\nEnter right Child of "<<frontnode->data<<" - ";
        cin>>rightData;
        if(rightData!=-1)
        {
        BinaryTreeNode<int>* rightchild= new BinaryTreeNode<int>(rightData);
        frontnode->right=rightchild;
        PendingNodes.push(rightchild);
        }

    }
    return root;
}

int main()
{
    BinaryTreeNode<int>* root = levelWise_Input();
    cout<<"No of Nodes-> "<<count_nodes(root); 
}