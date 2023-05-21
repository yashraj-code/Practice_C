/*
Height of Binary Tree
Complexity - O(n)
As we are visiting each and every node
*/

/*
In the iterative method, 
we find the height of the tree using the queue data structure. 

In this, we traverse the whole tree in a level-order traversal format,
where we maintain the nodes of each tree level in a queue data structure
until all the levels are traversed and 
return the count of the number of levels.

Algorithm

1. Insert the root of a tree into a queue.

2. Traverse the tree in level order,
inserting the child elements of all currently present nodes in the queue and removing those nodes.

3. Increment Count for each level in the queue.

4. Return the value of the counter when the queue becomes empty, 
i.e., when all the levels of the tree are traversed.

*/


/*
              1             - 2
             / \
            2   3           - 1
           / \  / \         
          4   5 6  7        - 0
*/

#include<iostream>
#include<list>

using namespace std;

class Node
{
    public:
        int data;
        Node* right;
        Node* left;

    Node(int val)
    {
        data=val;
        right=NULL;
        left=NULL;
    }
};


int heightOfTree(Node* root)
{   
    // Empty tree has a height equals 0
    if(root==NULL){return 0;}

    //Create an empty queue and insert the root node
    list<Node*> queue;
    queue.push_back(root);

    Node* front =NULL;
    int height=0;

    // Run a loop untill queue is empty
    while (!queue.empty())
    {
        
        //calculate the total number of nodes at the current level
        int size = queue.size();

        while (size--)
        {
            front=queue.front();
            queue.pop_front();

            if(front->left)
            {queue.push_back(front->left);}

            if(front->right)
            {queue.push_back(front->right);}
        }

    
    // Increment height by 1 for each level
    height ++;
    }

    return height;
}


int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<"Height of Binary tree is ";
    cout<<heightOfTree(root);
}
