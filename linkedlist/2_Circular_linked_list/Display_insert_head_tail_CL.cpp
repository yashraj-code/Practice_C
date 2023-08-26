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


void display(Node* head)
{
    // we cant use temp->next, it will not give us last element
    Node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while(temp!=head);
}

//have to point last node to the new head;
void insertAtHead(Node* &head,int val)
{
    Node* n=new Node(val);
    
    //corner case
    if(head==NULL)
    {
        n->next=n; //pointing to it self
        head=n;
        return;
    }

    Node* temp=head;

    while(temp->next!=head)
    {temp=temp->next;}

    temp->next=n;
    n->next=head;
    head=n;
}


void insertAtTail(Node* &head,int val)
{
    //corner case
    if(head==NULL)
    {insertAtHead(head,val);
    return;}

    Node* n=new Node(val);
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

int main()
{
        Node* head=NULL;
        insertAtHead(head,34);
        insertAtTail(head,56);
        insertAtTail(head,22);
        insertAtTail(head,1);
        display(head);
}