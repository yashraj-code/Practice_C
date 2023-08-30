#include <vector>
using namespace std;

//The syntax template <typename T> introduces a template parameter named T, 
// which can represent any data type. 

template <typename T>

// write now T is a variable
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T>*> children;

    // vector<TreeNode*> children;  // we can write this also
    // contains pointers of type Treenode 

    TreeNode(T data)
    {
        this->data=data;
    }
};