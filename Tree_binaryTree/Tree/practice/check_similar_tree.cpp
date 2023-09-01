/*
Given two Generic trees, return true if they are structurally identical 
i.e. they are made of nodes with the same values arranged in the same way.
*/

#include<iostream>
#include<bits/stdc++.h>  
#include<queue>
#include "tree_class.h"

using namespace std;

TreeNode<int>* level_wise_input()
{
    int rootData;
    cout<<"\nEnter root Data -> ";
    cin>>rootData;

    TreeNode<int> * root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() !=0)
    {
        TreeNode<int>* front_node = pendingNodes.front();
        pendingNodes.pop();
        cout<< "\nEnter num of Children of " <<front_node->data <<" -> ";
        int numChild;
        cin>>numChild;

        for(int i=0; i<numChild ; i++)
        {
            int childData;
            cout<<"\nEnter "<<i<<"th child of "<<front_node->data<<"-> ";
            cin>>childData;
            TreeNode<int> * child = new TreeNode<int>(childData);

            front_node->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

bool check(TreeNode<int>* root1 , TreeNode<int>* root2)
{
    if(root1->data!=root2->data)
        {return false;}
    
    int i=0;
    while(i< root1->children.size() || i<root2->children.size())
    {
        if(check(root1->children[i],root2->children[i]) == false)
        {return false;}
        i++;
    }

    return true;
}

int main()
{
    TreeNode<int>* root1 = level_wise_input();
    TreeNode<int>* root2 = level_wise_input();

    if(check(root1,root2)==true)
    {cout<<"True";}
    else
    {cout<<"False";}
}