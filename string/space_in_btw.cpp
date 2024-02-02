/*
Given a string you need to print all possible strings that can be made by placing spaces (zero or one) 
in between them. 
The output should be printed in sorted increasing order of strings

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".
*/

# include <iostream>
# include <string>
# include <vector>
# include<algorithm>

using namespace std;

    void rec(string input, string output, vector<string> &ans)
    {
        //base case
        if(input.empty())
        {ans.push_back(output);return;}
        
        // first letter
        string temp = input.substr(0,1);
        
        //delete this letter from input
        input.erase(0,1);
        
        // 2 choices
        //1--> add that letter to o/p
        rec(input,output+temp,ans);

        //2--> add that " "+letter to o/p
        rec(input,output+" "+temp,ans);
        
    }


int main()
{
    cout<<"Enter String -> ";
    string input;
    cin>>input;

    vector<string>ans;

    // we will insert first letter to OP string because space is not allowed on its left
    string output = input.substr(0,1);

    input.erase(0,1);

    // this will give us the count of elements present in it
    // we need this because we have created output array dynamically
    // we don't know how many elements were inserted

    rec(input,output,ans);

    sort(ans.begin(), ans.end());
}