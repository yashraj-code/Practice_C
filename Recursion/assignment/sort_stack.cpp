#include<iostream>
#include<stack>

using namespace std;

void insert(stack<int> &s, int val)
{
    if(s.empty() || s.top()<val)
        {s.push(val); return;}
    
    // if this is not the case
    int temp = s.top();
    s.pop();

    insert(s,val);
    // after this has returned we can insert whatever we had before
    s.push(temp);
    return;
}

void sort(stack<int> &s)
{
    //base case

    //stack of size one is sorted only
    if(s.size()==1)
        {return;}
    
    //if it is not sorted
    int val = s.top();
    s.pop(); 

    sort(s);

    // we will  assue that we will get sorted array here
    // now need to insert the element in the stack

    insert(s,val);

}

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(4);
    stack.push(5);
    stack.push(21);
    stack.push(2);
    stack.push(15);

    return 0;
}