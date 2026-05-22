// # this uses bracktracking (swapping)
#include<string>
#include<vector>
#include<iostream>

using namespace std;

void BT(string &input, int index, vector<string> &ans)
{
    //base condition
    // when we have iterated all he way to last element
    if(index==input.size())
    {ans.push_back(input);return;}

    // choices are charcters in string
    for(int i=index;i<input.size();i++)
    {
        // index swapping characters from index till ith position
        // Pass By Reference
        swap(input[index],input[i]);

        // now in new call index from next variable
        BT(input,index+1, ans);

        // backtracking
        // we leave its state as original variable was changed
        swap(input[index],input[i]);
    }
}

// Driver Code 
vector<string> main() 
{ 
    string str = "ABC"; 
    vector<string> v;
    //start index=0;

    BT(str,0,v);
    return v; 
} 