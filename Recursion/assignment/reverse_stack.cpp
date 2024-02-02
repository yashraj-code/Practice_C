#include<iostream>
#include<stack>

using namespace std;

void insert(stack<int> &s, int n)
{   
    if(s.size()==0)
        {s.push(n); return;}

    int temp = s.top();
    s.pop();
    insert(s,n);
    s.push(temp);
    return;
}

void rev(stack<int> &s)
{
    if(s.size()<=1)
    {return;}

    int temp = s.top();
    s.pop();

    rev(s);
    insert(s,temp);
    
    return;
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
    rev(stack);

    return 0;
}