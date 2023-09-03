/*
Given a tree, find and return the node for which sum of data of all children 
and the node itself is maximum. 
In the sum, data of node itself and data of immediate children is to be taken
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

// only need to consider immediate childrens
//fIRST -> NODE
//SECOND -> SUM
pair<int, int> node_with_max_child_sum(TreeNode<int>* root) 
{
    
    int max_sum = root->data;
    int max_node = root->data;

    //Handle leaf_nodes
    if(root->children.size()==0)
        {return {max_node, max_sum};}

    for (int i = 0; i < root->children.size(); i++) 
    {
        pair<int, int> result = node_with_max_child_sum(root->children[i]);

        // summing all the childrens
        // no we are summing all children complete subtrees not just the node
        // wrong
        // temp_sum=temp_sum+result.second;
        
        //Comparing each children
        if (max_sum<result.second) 
        {
        max_node = result.first;
        max_sum = result.second;
        }
    }

    //Add own roots data
    // temp_sum=temp_sum+root->data;
    // we can't do this suppose there are 3 nodes, this wil give the sum of aall the 3 sub trees
    // were as we just want node value not its whole subtree value

// caluclating sum of only children

    int child_sum=root->data;
    for (int i = 0; i < root->children.size(); i++) 
    {
        child_sum=child_sum+root->children[i]->data;
    }

    if(child_sum>max_sum)
    {
        max_node=root->data;
        max_sum=child_sum;
    }

    return {max_node, max_sum};
}


 int main()
 {
    TreeNode<int>* root=level_wise_input();
    cout<<node_with_max_child_sum(root).first;
 }