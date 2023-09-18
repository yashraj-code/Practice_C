// Remove all the duplicates in an array

/*
1st Approach -> 
make a secondary vector and for each element in given array
check if it is duplicate or not

if not insert that element in vector 

this will require us n*n complexity
as we are going to itereate whole array again and again
*/

/*
2nd Approach ->
like we did it in prime no
get max value of integer in that array , and create max+1 size array
where for every value you have an index

Problem is -> it will be disastrous if your given array has 5 elements
and 10^7 value is there.
*/

/*
3nd Approach ->
use hashtables , where 
key = Integer
value = True/False
*/

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

// to return vector of integers
// input is array and its size
vector<int> removeDuplicates(int *a, int size)
{
    vector<int> output;
    unordered_map<int,bool> seen;

    // We will use count to check if we have already inserted key-pair 
    for(int i=0; i<size; i++)
    {
        if(seen.count(a[i])==0)
        {
            //insert that key-pair
            seen[a[i]]=true;
            //as now we have seen it
            output.push_back(a[i]);
        }
    }
    return output;
}


int main()
{
    int a[] = {1,2,3,3,2,1,4,3,6,5,5};
    vector<int> output = removeDuplicates(a,11);

    for (int i = 0; i < output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
}

