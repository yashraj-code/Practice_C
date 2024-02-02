#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int> &s, int k)
{
    if(k==1)
        {s.pop();return;}

    int temp = s.top();
    s.pop();
    solve(s,k-1);

    s.push(temp);
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
    int k = ((stack.size())/2)+1;
    solve(stack,k)

    return 0;
}