#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* previous;

    Node(int val)
    {
        data=val;
        next=NULL;
        previous=NULL;
    }
};

void deletion(Node* head, int pos)
{
    if(pos==1)
    {DeleteAtHead(head);return;}

    Node* temp=head;
    int count=1;

    while(temp!=NULL && count!=pos)
    {
        temp=temp->next;
        pos++;
    }
    // now we are at that particular node which we want to delete
    temp->previous->next=temp->next;

    // for last node - we dont have its next
    if(temp->next!=NULL)
    {temp->next->previous=temp->previous;}

    delete temp;
}


void DeleteAtHead(Node* head)
{
    Node* temp=head;
    head=head->next;
    head->previous=NULL;

    delete temp;
}

void InsertAtHead(Node* &head,int val)
{
    Node* newnode= new Node(val);

    newnode->next=head;
    if(head!=NULL)
        {head->previous=newnode;}
        // in edge case
        //head is already null so- newnode->next=head is good
        // previous is not accesible in this case so if used
    head=newnode;
}

void InsertAtTail(Node* &head,int val)
{
    if(head==NULL)
        {InsertAtHead(head,val);
        return;}

    Node* newnode= new Node(val);
    Node* temp=head;
    
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->previous=temp;
}


void display(Node* head)
{
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
        Node* head=NULL;
        InsertAtHead(head,34);
        InsertAtTail(head,56);
        InsertAtTail(head,22);
        InsertAtTail(head,1);
        display(head);
}