/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

// recursion & DP
// store each result in memory  vector

#include<vector>
#include<iostream>

int rec(int steps, vector<int>&dp)
{
    //base case
    if(steps==0) return 1;
    if(steps<0) return 0;

    // if there is already a value for that step
    // return that value
    if(dp[steps]!=-1)   return dp[steps];

    int a = rec(steps-1,dp);
    int b = rec(steps-2,dp);
    dp[steps] = a+b;

    return dp[steps]; 
}

int climbStairs(int n) 
{
    vector<int> dp(n+1,-1);
    return rec(n,dp);
}