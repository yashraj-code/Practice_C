/*
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.



*/
#include <iostream>
#include <algorithm>

using namespace std;

void findTriplets(int arr[], int n, int x) 
{
    // Sort the array in ascending order
    sort(arr, arr + n);
    
    // we will use 3 pointer approach
    // 3rd pointer will be static 
    // rest of the two will move
    
    // iterate till 2nd last element
    for(int i=0;i<n-1;i++)
    {
        // Static element is always out of (left,right)
        // first element is the static element
        int left=i+1;
        int right = n-1;
        while(left<right)
        {
            int sum = arr[i]+arr[left]+arr[right];
            if(sum>x)
                {right--;}

            else if(sum<x)
                {left++;}

            else
                {
                    cout << arr[i] << ", " << arr[left] << ", " << arr[right] << endl;
                    left++;
                    right--;
                }
        }
    }

}

int main() {
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> x;

    findTriplets(arr, n, x);
    return 0;
}