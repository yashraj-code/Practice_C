/*
similar to https://www.hackerrank.com/contests/alcoding-summer-challenge/challenges/astronaut-pairs
sol - https://www.geeksforgeeks.org/finding-astronauts-from-different-countries/
*/

/*
Given a positive integer N denoting the number of astronauts(labelled from 0 from (N – 1))and 
a matrix mat[][] containing the pairs of astronauts that are from the same country, 
the task is to count the number of ways to choose two astronauts from different countries.
*/

// C++ program for the above approach

#include<bits/stdc++.h>
using namespace std;

// this function will return the no of neigh of a node
int dfs(int v, vector<vector<int> >& adj,
         vector<bool>& visited)
{
    //marking first node as visited
    visited[v]=true;
    int num =1;
    
    for(auto i:adj[v])
    {
        // if node is not visited call DFS
        if(!visited[i])
            {num=num+dfs(i,adj,visited);}
    }
    return num;
}

int count_pairs(int N, vector<pair<int,int> > astronauts)
{
    // Given -> N vertices
    //  we need to store size of every connected component
    
    // store adjancey list
    vector<vector<int>> adj(N);
    
    //construct adjancey list
    for(auto i:astronauts)
    {
        // i will ve vector and it will 2 values,p->i[0] and q->i[1]
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }
    
    vector<bool> visited(N,0);
    
    //stores size of each component
    vector<int> store;
    
    
    // running all vertices
    for(int i=0; i<N; i++)
    {
        if(!visited[i])
        {
            //visit it
            int count = dfs(i,adj,visited);
            store.push_back(count);
        }
    }
    
    
    // Stores the total number of ways to count the pairs
    int ans = N * (N - 1) / 2;
 
    // Traverse the array
    for (int i : store) {
        ans -= (i * (i - 1) / 2);
    }
 
    return ans;
    
    
}