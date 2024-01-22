// Returns the value of maximum profit
#include <bits/stdc++.h> 
#include<iostream>
using namespace std; 
#include<vector>

int knapSackRec(int W, int wt[], int val[], int n, vector<vector<int>> &dp) 
{ 
	// base condition 
	if (n == 0 || W==0)
		return 0;
        
    // already seen;
	if (dp[n][W] != -1) 
		return dp[n][W]; 

	if (wt[n] > W) 
    { 

		// Store the value of function call 
		// stack in table before return 
		dp[n][W] = knapSackRec(W, wt, val, n - 1, dp); 
		return dp[n][W]; 
	} 
	else { 
		// Store value in a table before return 
		dp[n][W] = max(val[n] + knapSackRec(W - wt[n], wt, val, n - 1, dp), 
					            knapSackRec(W, wt, val, n - 1, dp)); 

		// Return value of table after storing 
		return dp[n][W]; 
	} 
} 


// Driver Code 
int main() 
{ 
	int profit[] = { 60, 100, 120 }; 
	int weight[] = { 10, 20, 30 }; 
	int W = 50; 
	int n = sizeof(profit) / sizeof(profit[0]);
    // vector<vector<int>> myVector(rows, vector<int>(columns, -1));
    vector<vector<int>> vector1 (n+1, vector<int>(W+1,-1));
	cout << knapSackRec(W, weight, profit, n,vector1); 
	return 0; 
}