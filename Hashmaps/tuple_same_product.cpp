/*
Given an array nums of distinct positive integers, 
return the number of tuples (a, b, c, d) such that a * b = c * d 
where a, b, c, and d are elements of nums, and a != b != c != d.

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)

*/
#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) 
    {
        // so if we have s pairs or 4 no, then 8 ppermutaions would be possible
        // so for each 2 pairs we have 8 combination.

        // store pairs product and its frequency in map;

        unordered_map<int,int> freq;
        //each element product with other element
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int prod = nums[i]*nums[j];
                freq[prod]++;
            }
        }

        int ans =0;
        // now count frequency of products;
        // suppose if product frequency is 2, then there are 2 pairs in ans.

        for(auto [product, frequency] : freq)
        {
            //combination formula, bit simplified.
            int pairs = frequency * (frequency-1)/2;

            ans = ans + (pairs*8);
        }

        return ans;
        
    }
};