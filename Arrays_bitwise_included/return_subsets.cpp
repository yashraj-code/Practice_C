/*
Given an integer array (of length n), 
find and return all the subsets of input array.

Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.
*/

/*
The challenge is to now the size of each array after each itereation
we will make 2^n*n matrix and the 0th position of the row will indicate the size of the row
*/

// we will have 2^n subsets

// it is very similar to print_subsequence

#include <iostream>
#include <vector>
using namespace std;

// Function to generate all subsets of the integer array
void subsetHelper(vector<int> &nums, int pos, vector<int> curr, vector<vector<int>> &result)
{
    // Base case: When we reach the end of the array, add the current subset to the result
    if (pos == nums.size())
    {
        result.push_back(curr);
        return;
    }

    // Recursive case 1: Include the current element and generate subsets
    curr.push_back(nums[pos]);
    subsetHelper(nums, pos + 1, curr, result);
    

    // Recursive case 2: Exclude the current element and generate subsets (backtracking step)
    curr.pop_back();
    subsetHelper(nums, pos + 1, curr, result);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result; // 2D vector containing all the subsets
    vector<int> curr;           // 1D vector containing the current subset
    subsetHelper(nums, 0, curr, result);
    return result;
}

int main()
{

    vector<int> nums {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    int i, j;
    for (i = 0; i < result.size(); i++)
    {
        vector<int> subset = result[i];
        for (j = 0; j < subset.size(); j++)
        {
            cout << subset.at(j) << " ";
        }

        cout << endl;
    }
}
