/*
Given a random integer array A of size N.
Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

o/p
The first and only line of output contains the count of pair of elements in the array which sum up to 0.

*/

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int count_pair(int *a, int size)
{
    int count=0;
    unordered_map<int,int> seen;

    // frequency of each element
    for(int i=0;i<size;i++)
    {
        if(seen.count(a[i])==0)
            {seen[a[i]]=1;}
        else
            {seen[a[i]]++;}
    }

    for(int i=0;i<size;i++)
    {
        int complement = a[i]*-1;
        
        if(seen.count(complement)==1 && complement!=0)
        {            
            int temp = seen[complement]*seen[a[i]];
            seen.erase(complement);
            seen.erase(a[i]);
            count=count+temp;
        }
    }

    // to check for zero's
    // (n)*(n-1)/2
    
    if(seen.count(0)==1)
    {
        int freq_zero = seen[0];
        freq_zero = (freq_zero * (freq_zero-1))/2;
        count = count + freq_zero;
    }
    return count;
}

int main()
{
    int size;
    cout<<"Enter Size -> ";
    cin>>size;

    int a[size];

    cout<<"\nEnter Elements -> ";

    for(int i=0;i<size;i++)
        {cin>>a[i];}
    
    cout<<"\nAnswer is -> "<<count_pair(a,size);

}