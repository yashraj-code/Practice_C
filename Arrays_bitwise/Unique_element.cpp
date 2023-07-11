// Given an integer array of size 2N + 1. 
// In this given array, N numbers are present twice and one number is present only once in the array.
// You need to find and return that number which is unique in the array.

// Method 1 - 
// pick one element from array, now iterate on whole list if you get other occurence, element is not unique
// move to other element
// N^2

// Method 2 - 
// sort the array (nlogn)
// check adjacent elements, duplicate items will have similar adjacent values

// Method 3 is to use XOR operator
// for same no the XOR value is 0
// and 0^unique_element = unique_element 
// aslo it has associative property so sorting does not matter as n elements will have duplicates


#include<iostream>

using namespace std;


int get_unique(int arr[],int size)
{
    int temp=0;
    
    for(int i=0;i<size;i++)
        {temp=temp^arr[i];}
    
    return temp;
}


int main()
{
    int size;
    cout<<"enter size of array ";
    cin>>size;
    
    int arr[size];
    cout<<"Enter Elements ";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }

    cout<<get_unique(arr,size)<<endl;
}