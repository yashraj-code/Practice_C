#include<iostream>
#include<vector>

using namespace std;

bool isSubsetSum(int set[],int n,int sum)
{
    // base case
    // if size of array -> 0 and sum = 0;
    // then true rest all will be false
    bool dp[n+1][sum+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    
    for(int i=1;i<n+1;i++)
    {        
        for(int j=1;j<sum+1;j++)
            {
        //not to include
            if(j-set[i-1]<0)
                {dp[i][j]=dp[i-1][j];}
            else
                {dp[i][j] = dp[i-1][j-set[i-1]] || dp[i-1][j];}
            }
    }

    return dp[n][sum];
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}