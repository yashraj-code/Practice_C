#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>

using namespace std;

void permute(string ip, string op, vector<string> &ans)
{
    //base condition
    if(ip.size()==0)
    {ans.push_back(op);return;}
    unordered_set<char> visited;

    // choices are charcters in string
    for(int i=0;i<ip.size();i++)
    {
        if(visited.count(ip[i])==0)
            {
                visited.insert(ip[i]);
                // new input -> remove i th charcter from string
                string new_ip = ip.substr(0,i) + ip.substr(i+1);

                // new output -> add ith charcter at back of string
                string new_op = op+ip[i];

                permute(new_ip, new_op , ans);
            }
    }
}

// Driver Code 
vector<string> main() 
{ 
    string str = "ABC"; 
    vector<string> v;
    // ip = str
    // op = ""
    permute(str,"",v);
    return v; 
} 