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
        cout<<temp->data<<endl;
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

bool search(Node* head, int key)
{
    Node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main()
{
    Node* head=NULL;
    InsertAtHead(head,5);
    InsertAtHead(head,23);
    InsertAtHead(head,78);
    InsertAtHead(head,12);
    
    display(head);

    cout<<search(head, 23)<<endl;
    cout<<search(head, 24)<<endl;

    return 0;
}

