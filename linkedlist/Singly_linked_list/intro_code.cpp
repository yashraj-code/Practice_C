class Node
{
    public:
        int data;
        Node* next;
    
};

int main()
{
    //Declaring Pointer of type Node
    Node* new_node;

    //creating a node
    new_node=new Node();

    //access the memebers of the node
    new_node->data=10;
    new_node->next=NULL;

}