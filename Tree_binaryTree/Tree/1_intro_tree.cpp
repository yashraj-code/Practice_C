#include <iostream>
#include "tree_class.h"

using namespace std;

int main() 
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(11);
    TreeNode<int>* child2 = new TreeNode<int>(12);

    root->children.push_back(child1);
    root->children.push_back(child2);
    return 0;
}