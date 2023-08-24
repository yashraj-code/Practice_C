// This includes  if there is no element in the list or one element only

// This will not work if we are deleting head_node

// void DeleteAtHead(Node* &head)
// {
//     //storing just to release the mem
//     Node* temp=head;
//     head=head->next;
//     delete temp;
// }

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

// DELETE NTH NODE
// we will not be searching for the node that goinig to be deleted
// we will be sitting at a node and searching value in front one.
void deletion(Node* head, int val)
{

    //if linklist is empty
    if(head==NULL)
        {return;}

    //if there is only one element
    if(head->next==NULL)
    {
        // DeleteAtHead(head);
        return;
    }

    Node* temp=head;
    // temp->next will point to next node.
    // temp->next->data will return data from next node
    while (temp->next->data!=val)
	    {temp=temp->next;}

    // we need to release that memory
    Node* todelete=temp->next;
    temp->next=temp->next->next;

    delete todelete;
}

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

int main()
{
    Node* head=NULL;
    InsertAtHead(head,5);
    InsertAtHead(head,23);
    InsertAtHead(head,78);
    InsertAtHead(head,12);
    
    display(head);
    deletion(head, 23);
    cout<<""<<endl;
    display(head);

    return 0;
}

