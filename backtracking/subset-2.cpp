// it will handle duplicates in the input array and generate all unique subsets.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
    // 1. GOAL: Every node in the tree is a valid subset.
    // So we "take the photo" immediately at the start of every call.
    for(auto i:temp)
        {cout<<i<<" ";}

    cout<<endl;
    ans.push_back(temp);

    // 2. ITERATE OVER CHOICES
    // We loop from 'index' to the end.
    for (int i = index; i < nums.size(); i++) 
    {
        // HANDLE DUPLICATES
        if (i > index && nums[i] == nums[i-1]) 
        {
            continue; // Skip! We already processed a '2' at this level.
        }
        
            // 3. DO
        temp.push_back(nums[i]);

        // 4. RECURSE
        // Pass 'i + 1' because we can't reuse the current number 
        // and we can't look back (Index Strategy).
        solve(i + 1, nums, temp, ans);
        
        // 5. UNDO (Backtrack)
        temp.pop_back();
    }
}

int main() 
{
    vector<int> nums = {1, 2, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    solve(0, nums, temp, ans);
    return 0;
}