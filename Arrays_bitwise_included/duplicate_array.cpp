/*Given an array of integers of size n which contains numbers from 0 to n - 2
Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once 
and one number is present twice. You need to find and return that duplicate number present in the array.
Assume, duplicate number is always present in the array.
*/

// Method 1 - 
// pick one element from array, now iterate on whole list if you get other occurence, element is not unique
// move to other element
// N^2

// Method 2 - 
// sort the array (nlogn)
// check adjacent elements, duplicate items will have similar adjacent values

// Method 3 is to use formaula (n)(n+1)/2
// We know that if n=n-2 then the above formaula will give us sum of a perfect series without any duplicates
// on one side we can have the entire sum of array
// If we subtract these 2 we will the no which is duplicated


#include<iostream>

using namespace std;


int get_duplicate(int arr[],int size)
{
    int sum=0;
    
    for(int i=0;i<size;i++)
        {sum=sum+arr[i];}
    
    int n=size-2;

    //n(n+1)/2
    int org_sum =(n*(n+1))/2;

    return sum-org_sum; 
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

    cout<<"Ans = "<<get_duplicate(arr,size)<<endl;
}