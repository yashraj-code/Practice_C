/*

We will print like this
1 : 2 , 3
2 :
3 :

*/

// PREORDER TRAVERSAL

#include <iostream>
#include "tree_class.h"

using namespace std;

// we will be receiving tree type pointer
void printTree(TreeNode<int>* root)
{
    if(root==NULL){return;}
    
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
    TreeNode<int>* root   = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);

    root->children.push_back(child1);
    root->children.push_back(child2);
    printTree(root);
}