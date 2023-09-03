/*
Given a generic tree, find and return the node with second largest value in given tree. 
Return NULL if no node with required value is present
*/

/*
If each subtree will give 2nd highest node
and suppose there is a subtree with only one node which is actaully ans but it will
give 2nd as NULL as we wnat to get 2nd highest from each subtree

Approach 
-> get both highest and 2nd highest
-> compare them 

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

pair<int,int> second_largest(TreeNode<int>* root)
{
    int max_node = root->data;
    int second_max = -1;

    //base for leaf node
    if(root->children.size()==0)
    {return{max_node,second_max};}

    for(int i=0; i<root->children.size(); i++)
    {
        pair <int,int> result = second_largest(root->children[i]);
        int result_max=result.first;
        int result_second_max = result.second;

        int temp_max=max_node;

        // for maximum
        if(result_max>max_node)
            {temp_max=result_max;}

        //second_max
        //compare with new max

        //if max has changed
        if(max_node!=temp_max)
        {
            // compare y2 with x1
            if(result_second_max>max_node)
                {second_max=result_second_max;}
            else
                {second_max=max_node;}
        }
        else // value of max is not changed
        {
            //compare y1 with x2
            if(second_max<result_max)
                {second_max=result_max;}
        }

        max_node=temp_max;
    }
    return{max_node,second_max};
}

int main()
{
    TreeNode<int>* root = level_wise_input();
    cout<<second_largest(root).second;
}