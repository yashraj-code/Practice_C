/*Given a no, count no of zeros in it
*/


#include<iostream>

using namespace std;

int count(int n)
{
    // base case
    //if(n==0) {return 0;}
    //problem with this is that it does not cover the edge case, where n is itself 0
    if(n<=9)
    {
        if(n==0)    {return 1;}
        else    {return 0;}
    } 

    //calculation part
    int ans;
    if (n%10==0)
        {ans = 1+count(n/10);}
    else
        {ans = count(n/10);}
    
    return ans ;
}

int main()
{
    int x,n;
    cout<<"Enter x -> ";
    cin >> x;

    int ans=count(x);

    cout<<"Ans -> "<<ans;
}