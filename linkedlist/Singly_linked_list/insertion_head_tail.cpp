#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        //Constructor
        Node(int val)
        {
            data=val;
            next=NULL;
        }
};


void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    
}

void InsertAtHead(Node* &head,int val)
{
    //creating new node
    Node* new_node=new Node(val);
    new_node->next=head;
    head=new_node;
}

void InsertAtTail(Node* &head,int val)
{
    Node* new_node=new Node(val);

    //case when list is empty
    if(head==NULL)
    {
        head=new_node;
        return;
    }

    Node* temp= head;

    // We have to stop at last node not when node is NULL
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }

    // we will get last node at end of iteration
    temp->next=new_node;

}



int main()
{
    Node* head=NULL;
    InsertAtTail(head,5);
    InsertAtTail(head,23);
    InsertAtTail(head,78);
    display(head);
    InsertAtHead(head,12);
    display(head);
    return 0;
}
