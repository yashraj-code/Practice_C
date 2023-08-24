#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data=val;
            next=NULL;
        }
};

void PrintBackwards(Node* head)
{
    if(head==NULL)
        {return;}

    PrintBackwards(head->next);
    cout<<head->data<<" ";
}

int main()
{
    Node* head = new Node(10);
    Node* second_node = new Node(11);
    head->next = second_node;
    Node* third_node = new Node(12);
    second_node->next=third_node;
    PrintBackwards(head);
    return 0;
}
