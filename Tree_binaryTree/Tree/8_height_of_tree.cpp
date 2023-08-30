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

    // Now if we insert 1 as a integer in queue
    // then how will we connect with children, because when we will pop it out
    // it will come out as a integer.

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

int height_Tree(TreeNode<int>* root)
{
    int level=1;
    for(int i=0;i<root->children.size();i++)
    {
        int temp =height_Tree(root->children[i])+1;
        level=max(temp,level);
    }
    return level;
}


 int main()
 {
    TreeNode<int>* root=level_wise_input();
    int ans = height_Tree(root);
    cout<<ans;
 }