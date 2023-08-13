/*
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.

Input : 4
Output : 7

*/


//Array APPROACH

// we will store the ans in an array

//complexity = O(n)

#include<iostream>
using namespace std;

int staircase(int n)
{

    int a[n+1];

    //+1 to store zero also
    //base case
    a[0]=1;
    a[1]=1;
    a[2]=2;

    for(int i=3;i<=n;i++)
    {
        a[i] = a[i-1] + a[i-2] + a[i-3];
    }

    return res[n];
}

int main()
{
    int n;
    cout<< "Enter no";
    cin>>n;


    cout<<staircase(n)<<endl;


}