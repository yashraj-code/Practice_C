// Check whether the array is sorted or not

#include<iostream>
using namespace std;

/*
we say if func(array) -> a[0]<a[1] and func(array-1)
if both returns true then it is sorted
*/

bool recursion(int *array, int n)
{
    // base case 
    if(n==0)
        {return true;}

    if (array[n-2]>array[n-1])
        {return false;}
    
    return recursion(array,n-1);
}

int main()
{
    int arr[] = {1, 2, 3, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (recursion(arr, size))
        cout << "The array is sorted in non-decreasing order." << endl;
    else
        cout << "The array is NOT sorted in non-decreasing order." << endl;

    return 0;
}