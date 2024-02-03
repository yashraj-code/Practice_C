/*
N steps, atmost k steps one can take
*/

#include<vector>
#include<iostream>

using namespace std;

//APPROACH 1 - TDURSION
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

//APPROACH 2 - TOP DOWN

int TD_countways(int n,int k, int *dp)
{
    if(n==0)
        {return 1;}
    if(n<=0)
        {return 0;}
    
    if(dp[n]!=-1)
        {return dp[n];}
    
    int sum=0;
    for(int jump=1;jump<=k;jump++)
        {sum=sum+TD_countways(n-jump,k,dp);}
    
    return dp[n]=sum;
}

// APPROACH 3 - BOOTOM UP APPROACH
int BU_countsteps(int n, int k)
{
    //iterative approach
    //convert recursion to for loops
    vector<int> dp(n+1,0);
    dp[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int jump=1;jump<=k;jump++)
        {
            if(i-jump>=0)
                {dp[i] = dp[i] + dp[i-jump];}
        }
    }
    return dp[n];
}





int main()
{
int n = 4;
int k=3;
//approach 1
cout<<REC_countways(n,k);

//approach 2
int dp[1000]={-1};
cout<<TD_countways(n,k,dp);
return 0;
}