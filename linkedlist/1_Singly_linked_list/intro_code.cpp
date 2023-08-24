#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        // as node is a datatype and we need pointer to it 
        Node* next;

        //similar to int a=11;  int *pointer; pointer=&a;

        // paramterized Constructor
        Node(int val)
        {
            data=val;
            next=NULL;
        }
};

int main()
{
    //Declaring Pointer of type Node
    Node* new_node;

    //creating a node
    new_node=new Node(10);

    //access the memebers of the node
    cout<<new_node->data<<endl;
    cout<<new_node->next<<endl;

}