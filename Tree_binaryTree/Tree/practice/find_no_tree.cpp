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

bool find(TreeNode<int>* root, int value)
{
    if(root->data==value)
        {return true;}

    for(int i=0; i<root->children.size(); i++)
    {
        if(find(root->children[i],value)) //will only work if true is returned
        {return true;}
    }
    return false;
}

int main()
{
    int value;
    cout<<"Enter value to search";
    cin>>value;

    TreeNode<int>* root = level_wise_input();
    if(find(root,value))
        {cout<<"true";}
    else
        {cout<<"false";}
}