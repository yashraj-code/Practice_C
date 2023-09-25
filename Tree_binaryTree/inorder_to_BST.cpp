#include <iostream>
#include <vector>

using namespace std;

class TreeNode 
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
		{
		data = val;
		left = NULL;
		right = NULL;
		}
};

TreeNode* buildBSTFromInorder(vector<int>& inorder, int left, int right) 
{
    if (left > right) 
	{
        return NULL;
    }

    int mid = (right + left) / 2; // Calculate the middle index
    TreeNode* root = new TreeNode(inorder[mid]); // Create a new node for the middle element

    // Recursively build left and right subtrees
    root->left = buildBSTFromInorder(inorder, left, mid - 1);
    root->right = buildBSTFromInorder(inorder, mid + 1, right);

    return root;
}


// Function to print the inorder traversal of a BST
void inorderTraversal(TreeNode* root) 
{
    if (root == NULL) 
	{
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() 
{
    vector<int> inorder = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = buildBSTFromInorder(inorder, 0, inorder.size() - 1);

    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
