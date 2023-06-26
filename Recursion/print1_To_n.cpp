// code to print number from 1 to n in increasing order recursively

#include<iostream>

using namespace std;


void print(int x)
{
    if(x==0){return;}
    
    print(x-1);
    cout<<x<<" ";
}

int main()
{
    int x;
    cout<< "Enter no- > ";
    cin >> x;

    print(x);
}