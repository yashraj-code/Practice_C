/*
You are given an array of integers that contain numbers in random order. 
Write a program to find and return the number which occurs the maximum times in the given input.
*/

/*
store element and its frequency in the unordered map
while iterating 
-> maintain a variable of max key-value pair int
-> check if this pair is still largest simulatanously
*/



#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int max_frequency(int *a, int size)
{
    unordered_map<int, int> seen;
    int max_freq=1;
    int max_key = a[0];

    for (int i = 1; i < size; i++)
    {
        // check if key-value pair exists or not
        if(seen.count(a[i])==0)
        {
            //does not exist
            seen[a[i]]= 1; 
        }
        else
        {
            //increment by 1
            seen[a[i]]=seen[a[i]]+1;

            if(seen[a[i]]>max_freq)
            {
                max_freq = seen[a[i]];
                max_key= a[i];
            }
        }
    }
    return max_key;
}

int main()
{
    int size; 
    cout<<"Enter size";
    cin>>size;

    int a[size];

    for (int i = 0; i < size; i++)
        {cin>>a[i];}
    
    int ans = max_frequency(a,size);

    cout<<ans;
}