// level wise we always use a queue
// First in first out (FIFO) type of arrangement. 
// Elements are inserted at the back (end) and are deleted from the front.

// The queue contains all the nodes whose children are not asked
// First root is inserted (1)
// pop it and ask its children (2,3,4)
// get the children connected with root & insert them in queue also

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
            cout<<"\nEnter "<<i<<"th child of "<<front_node->data<<"-> ";
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


void print_levelwise_Tree(TreeNode<int>* root)
{
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while (pendingNodes.size()!=0)
    {
        //Select particular root
        TreeNode<int> * front_node = pendingNodes.front();
        cout<<front_node->data<<": ";
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
    TreeNode<int>* root=level_wise_input();
    print_levelwise_Tree(root);
 }