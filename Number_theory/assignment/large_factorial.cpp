#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void multiply(vector<int> &a , int no ,int &size)
{
    int carry =0;
    for(int i=0; i<size ;i++)
    {
        int product = a[i]*no+carry;
        a[i] = product%10;
        carry = product/10;
    }

    while(carry)
    {
        a[size] = carry %10;
        carry = carry /10;
        size++;
    }
}

void bigFactorial(int n)
{
    // we can use string also
    vector<int> a(1000,0);
    a[0]=1;
    int size=1; //to keeep check till what size out ans is

    for(int i=2 ; i<=n; i++)
    {
        multiply(a,i,size);
    }
    
    // instead of returning , we are pinting in reverse order
    // print the results in reverse order

    for(int i=size -1; i>=0;i--)
        {cout<<a[i];}
    
    cout<<endl;
}

int mmain()
{
    int n;
    cin>>n;
    bigFactorial(n);

    return 0;
}