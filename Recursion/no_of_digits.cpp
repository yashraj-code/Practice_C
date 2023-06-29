//find out and return the number of digits present in a number 

#include<iostream>
using namespace std;

int count(int n)
{
    // base case
    if(n==0){return 0;}

    // f(x)=1+f(x/10)
    int small_out=1+count(n/10);
    return small_out;
}

int main()
{
    int x;
    cout<<"Enter digit-> ";
    cin>>x;

    int ans = count(x);
    cout<<ans;
}