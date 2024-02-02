/*
N steps, atmost k steps one can take
*/

//APPROACH 1 - RECURSION

#include<vector>
#include<iostream>

using namespace std;

int REC_countways(int n,int k)
{
    if(n==0)
        {return 1;}
    if(n<=0)
        {return 0;}
    
    int sum=0;
    for(int jump=1;jump<=k;jump++)
        {sum=sum+REC_countways(n-jump,k);}
    
    return sum;
}

int main()
{
int n = 4;
int k=3;
cout<<REC_countways(n,k);
return 0;
}