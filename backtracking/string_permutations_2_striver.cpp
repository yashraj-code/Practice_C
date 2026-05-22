// # this uses recursion only not bracktracking
// by striver

#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

void permute(string ip, string op, vector<string> &ans, unordered_set<char> &visited)
{
    //base condition
    if(op.size()==ip.size())
        {ans.push_back(op);return;}

    // choices are charcters in string
    for(int i=0;i<ip.size();i++)
    {
        // checking in set if its visited or not
        //if not visited
        if(visited.count(i)==0)
            {
                //visit
                visited.insert(i);
                // new output -> add ith charcter at back of string
                op.push_back(ip[i]);
                permute(ip, op, ans, visited);
                op.pop_back();
                visited.erase(i);
            }
    }
}

// Driver Code 
int main() 
{ 
    string str = "ABC"; 
    vector<string> ans;
    string op="";
    unordered_set<char> visited;
    // ip = str
    // op = ""
    permute(str,op,ans, visited);
    for(auto i:ans)
    {cout<<i<<", ";}

    return 0;
} 