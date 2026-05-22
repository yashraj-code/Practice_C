// Given input array and generate all subsets
#include <iostream>
#include <vector>
using namespace std;

void solve(int index,
           vector<int>& nums,
           vector<int>& temp,
           vector<vector<int>>& ans)
{
    // BASE CASE
    // When we have processed all elements
    if (index >= nums.size())
    {
        // every leaf node is a subset
        for (int x : temp)
            cout << x << " ";
        cout << endl;

        ans.push_back(temp);
        return;
    }

    // -------------------------
    // CHOICE 1: PICK
    // -------------------------
    temp.push_back(nums[index]);
    solve(index + 1, nums, temp, ans);
    temp.pop_back();   // undo

    // -------------------------
    // CHOICE 2: NOT PICK
    // -------------------------
    solve(index + 1, nums, temp, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, nums, temp, ans);

    return 0;
}
