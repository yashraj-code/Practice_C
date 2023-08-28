/*

// 1 - ask root
// 2 - ask how many elements as children
// 3 - for loop on it 
// 4 - pass it recursively for sub trees

*/

#include <iostream>
#include "tree_class.h"

using namespace std;

// after taking all the vlaues it should return root of the tree

TreeNode<int> * takeInput()
{
    int rootData;
    cout<<"\nEnter Data -> ";
    cin>>rootData;

    //create its object
    TreeNode<int> * root = new TreeNode<int>(rootData);

    int n;
    cout<<"\nEnter num of Children of "<<rootData<<" -> ";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        TreeNode<int> * child = takeInput();
        root->children.push_back(child);
    }

    return root;
}


// we will be receiving tree type pointer
void printTree(TreeNode<int>* root)
{
    cout<<root->data<<":";

    //For printing all the childrens data first
    for(int i=0; i<root->children.size(); i++)
        {cout<<root->children[i]->data<<",";}
    
    cout<<endl;

    //Now move for root = child[1]
    for(int i=0; i<root->children.size();i++)
        {printTree(root->children[i]);}

}


int main()
{
    TreeNode<int>* root   = takeInput();
    printTree(root);
}