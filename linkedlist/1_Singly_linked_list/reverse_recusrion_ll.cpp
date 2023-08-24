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

// RECURSIVE WAY
Node* reverseRecursive(Node* &head)
{   
    // for edge case where list is empty or one element
    if (head==NULL || head->next==NULL)
    {
        return head;
    }
    
    // this will be constant all throught run
    // this is the last node that just become first (not head)
    Node* newhead = reverseRecursive(head->next);
    
    // 2nd last node
    // 2ndlast->next=last; last->next = 2ndlast
    // it reversed
    head->next->next=head;
    head->next=NULL;
    // everypair of two nodes will be taken care of
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
    display(head);

    return 0;
}