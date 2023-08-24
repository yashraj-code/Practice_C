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

//RECURSIVE WAY

// void recursive_display(Node* head)
// {
//     if (head==NULL)
//         {return;}
    
//     cout<<head->data<<endl;
//     recursive_display(head->next);
// }

int main()
{
    // Declaring

    Node* head = new Node(10);
    Node* second_node = new Node(11);
    head->next = second_node;
    Node* third_node = new Node(12);
    second_node->next=third_node;
    display(head);
    return 0;
}