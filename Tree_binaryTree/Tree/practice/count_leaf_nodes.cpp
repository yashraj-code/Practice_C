#include<iostream>
#include<queue>
#include "tree_class.h"

using namespace std;

TreeNode<int>* level_wise_input()
{
    int rootData;
    cout<<"\nEnter root Data -> ";
    cin>>rootData;

    //create its object
    TreeNode<int> * root = new TreeNode<int>(rootData);

    //inbuilt queue
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    // Till the queue is not empty
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
            cout<<"\nEnter "<<i<<" th child of "<<front_node->data<<"-> ";
            cin>>childData;
            TreeNode<int> * child = new TreeNode<int>(childData);
            //connect with root
            front_node->children.push_back(child);
            // push it in the queue as well
            pendingNodes.push(child);
        }
    
    }
    return root;
}

int count_leaf_nodes(TreeNode<int>* root)
{
    // if no children then increase count by 1

    int count=0;
    // base case if there is no children
    if(root->children.size()==0)
        {
            return 1; 
        }
    
    for(int i=0;i<root->children.size();i++)
    {
        count =count+count_leaf_nodes(root->children[i]);
    }
    return count;
}


 int main()
 {
    TreeNode<int>* root=level_wise_input();
    int ans = count_leaf_nodes(root);
    cout<<ans;
 }