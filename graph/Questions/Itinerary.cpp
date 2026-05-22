// https://leetcode.com/problems/reconstruct-itinerary/description/

/*
You are given a list of airline tickets where 
tickets[i] = [fromi, toi] represent the departure 
and the arrival airports of one flight. 

Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", 
thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. 

You must use all the tickets once and only once.

*/


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

class Solution 
{
public:
    unordered_map<string, vector<string>> graph;
    vector<string> itinerary;

    void dfs(string& airport)
    {
        while(!graph[airport].empty())
        {
            string next = graph[airport].back();
            graph[airport].pop_back();
            dfs(next);
        }
        itinerary.push_back(airport);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for(auto ticket : tickets)
            {graph[ticket[0]].push_back(ticket[1]);}
        
        for(auto temp : graph)
            {sort(temp.second.rbegin(), temp.second.rend());}

        string jfk = "JFK";
        dfs(jfk);

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};