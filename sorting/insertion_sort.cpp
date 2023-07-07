#include<iostream>

using namespace std;

// The first element in the array is assumed to be sorted.
// Take the second element and store it separately in key.

void insertion_sort(int arr[],int size)
{
    // make 1st element as key
    // it will act like left side value
    // it will be used further to compare left side value 
    for(int step=1;step<size;step++)
    {
        int key=arr[step];
        int j=step-1;

    // It will enter the loop only if the element on adjacent left is greater than it (key) 
    // if the element is greater then enter the loop &&
    // Compare key with each element on the left of it until an element smaller than it is found.
    // As j an go least till 0
    while(key<arr[j] && j>=0)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
    }
}

int main()
{
    int size;
    cout<<"no of elements"<<endl;
    cin>>size;
    
    int a[size];
    cout<<"Enter Elements";

    for(int i=0;i<size;i++)
        cin>>a[i];

    insertion_sort(a,size);

    for (int i=0;i<size;i++)
        cout<<a[i]<<" ";
}