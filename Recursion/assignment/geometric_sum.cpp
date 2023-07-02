/*
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion. 
*/


#include <iostream>
#include <cmath>

using namespace std;

float geometric_sum(int k)
{
    // base case
    if(k==0) {return 1;}

    //return part
    // 1/k = 1/(k-1)*2 + 1/(k-1)
    float calc = 1/pow(2,k) + geometric_sum(k-1); 
    return calc;

}

int main()
{
    int k;
    cout<<"Enter k -> ";
    cin >> k;

    float ans=geometric_sum(k);

    cout<<"Ans -> "<<ans;
}