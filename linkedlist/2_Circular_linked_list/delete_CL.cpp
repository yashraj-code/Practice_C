// Includes - deletion, deleteAtHead
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

void deletion(Node* &head,int pos)
{
    //pos= position of Node to be deleted

    //head delete
    if(pos==1)
    {deleteAtHead(head)}
    
    Node* temp=head;
    int count=1;

    //stop before one Node 
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }

    //tail taken care of
    Node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void deleteAtHead(Node* &head)
{
    Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    // we are last Node here
    Node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}

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
        deletion(head,56);
        display(head);
}