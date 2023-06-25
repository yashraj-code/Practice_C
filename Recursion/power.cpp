// A program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.

#include<iostream>

using namespace std;

int power(int x,int n)
{
    // base case
    if(n==0) {return 1;}

    //return part
    // x^n = n * x^ n-1
    int small_out = x*power(x,n-1);
    return small_out;

}

int main()
{
    int x,n;
    cout<<"Enter X -> ";
    cin >> x;

    cout<<"Enter power -> ";
    cin >> n;

    int ans=power(x,n);

    cout<<"Ans -> "<<ans;
}