// Just include this in the code.h file

/*
	~TreeNode() 
    {
		for (int i = 0; i < children.size(); i++) 
        {
			delete children[i];
        }
	}
*/

// OR

/*
void deleteTree(TreeNode<int>* root) {
	for (int i = 0; i < root->children.size(); i++) {
		deleteTree(root->children[i]);
	}
	delete root;

*/