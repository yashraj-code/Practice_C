/*
Given a generic tree and an integer n.
Find and return the node with next larger element in the Tree
i.e. find a node with value just greater than n.
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

// Each sub-tree will give a value 
// which we will check is greater or not
// if nothing is found ans = -1
int next_largest(TreeNode<int>* root,int value)
{
    int ans = -1;
    if(root->data > value)
    {ans=root->data;}

    for(int i=0;i<root->children.size();i++)
    {
        int temp_value = next_largest(root->children[i],value);
        
        if(temp_value!=-1 && ans!=-1)
        {
            //greater than value but less than we have currently as ans
            if(temp_value>value && temp_value<ans)
            {
                ans=temp_value;
            }
        }
        else
        {
            // case where either of one is -1
            // case where ans= -1 but temp has some value 
            ans=temp_value;
        }
        
    }

    return ans;
}

int main()
{
    int value;
    cout<<"Enter Integer";
    cin>>value;

    TreeNode<int>* root =level_wise_input();
    cout<<"\n"<<next_largest(root,value)<<endl;

    return 0;
}
