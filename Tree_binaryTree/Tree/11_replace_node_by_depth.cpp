/*
In a given Generic Tree, replace each node with its depth value.
You need to just update the data of each node, no need to return or print anything.

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

void replace_with_depth(TreeNode<int>* root,int depth)
{
    root->data=depth;

    for(int i=0;i< root->children.size(); i++)
    {
        replace_with_depth(root->children[i], depth+1);
    }
    return;
}

void print_levelwise_Tree(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    cout<<root->data<<endl;
    while (pendingNodes.size()!=0)
    {
        //Select particular root
        TreeNode<int> * front_node = pendingNodes.front();
        // cout<<front_node->data<<": ";
        pendingNodes.pop();

        //insert all the children of the particular root into queue
        for(int i =0; i<front_node->children.size();i++)
        {
            cout<<front_node->children[i]->data<<",";
            pendingNodes.push(front_node->children[i]);
        }
        cout<<endl;
    }
}


int main()
{
    TreeNode<int> * root = level_wise_input();
    replace_with_depth(root,0);
    cout<<endl;
    print_levelwise_Tree(root);
}