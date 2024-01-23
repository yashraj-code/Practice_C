#include<iostream>
#include<vector>

using namespace std;

bool isSubsetSum(int set[],int n,int sum, vector<vector<int>> &dp)
{
    // base case
    // if size of array -> 0 and sum = 0;
    // then true rest all will be false

    //this first so that condition is true
    if(sum==0)
        {return true;}
    
    if(n==0)
        {return false;}
    
    //visited
    if(dp[n-1][sum]!=-1)
        {return dp[n-1][sum];}
    
    
    //not to include
    if(sum-set[n-1]<0)
    {
        dp[n-1][sum]=isSubsetSum(set,n-1,sum,dp);
        return dp[n-1][sum];
    }
    else
    {
        dp[n-1][sum] = isSubsetSum(set,n-1,sum-set[n-1],dp) || isSubsetSum(set,n-1,sum,dp);
        return dp[n-1][sum];
    }
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    vector<vector<int>> dp (n+1,vector<int> (sum+1,-1));
    if (isSubsetSum(set, n, sum, dp) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}