// ITERATIVE WAY (sliding pointers)

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
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

// as we are returning head
Node* reverse(Node* &head)
{
    Node* previous=NULL;
    Node* current=head;
    Node* nextNode;

    while (current!=NULL)
    {
        nextNode=current->next;
        //reversing this connection
        current->next=previous;

        //we will move all the pointers one step ahead
        previous=current;
        current=nextNode;
        
    }
    //new head
    return previous;

}

int main()
{
    // Declaring

    Node* head = new Node(10);
    Node* second_node = new Node(11);
    head->next = second_node;
    Node* third_node = new Node(12);
    second_node->next=third_node;
    display(head);
    cout<<"\nAfter reverse\n"<<endl;
    Node* new_head = reverse(head);
    display(new_head);

    return 0;
}