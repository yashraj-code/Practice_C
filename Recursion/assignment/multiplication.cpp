/*Given two integers m & n, calculate and return their multiplication using recursion. 
You can only use subtraction and addition for your calculation. No other operators are allowed.
Input format : m and n (in different lines)
*/


#include<iostream>

using namespace std;

int multi(int m,int n)
{
    // base case
    if(n==0 || m==0) {return 0;}

    //return part
    // 2m = m+m 
    int calc = m+multi(m,n-1);
    return calc;

}

int main()
{
    int m,n;
    cout<<"Enter m -> ";
    cin >> m;

    cout<<"Enter n -> ";
    cin >> n;

    int ans=multi(m,n);

    cout<<"Ans -> "<<ans;
}