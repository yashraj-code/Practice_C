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

void print_nodes_at_level(TreeNode<int>* root,int level)
{
    // we will use top to bottom Approach
    // At each recursive call level will decrease by 1
    //if level is zero we are at good part

    if(level==0)
        {cout<<root->data<<","; return; }
    
    for(int i=0;i<root->children.size();i++)
    {
        print_nodes_at_level(root->children[i],level-1);
    }
}


 int main()
 {
    TreeNode<int>* root=level_wise_input();
    int level=0;
    cout<<"Give level no-> ";
    cin>>level;
    print_nodes_at_level(root,level);
 }