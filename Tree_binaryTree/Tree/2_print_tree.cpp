// The problem withg this code is that we are not sure in print statement 
// that whether the tree looked like this 

/*
            1                   1
          /  \          or       \
        2     3                   2
                                   \
                                    3
*/

#include <iostream>
#include "tree_class.h"

using namespace std;

// we will be receiving tree type pointer
void printTree(TreeNode<int>* root)
{
    cout<<root->data<<endl;
    // now we will go each childer in the vector 
    // and again call this function (RECURSIVE)

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

// output
// 1
// 2
// 3
