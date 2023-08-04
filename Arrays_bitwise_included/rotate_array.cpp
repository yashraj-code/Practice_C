/*
Given a random integer array of size n, 
write a function that rotates the given array by d elements (towards left)
*/
#include<iostream>

using namespace std;

void rotate(int a[], int size, int shift)
{
    int temp[shift];
    for(int i=0; i < shift; i++)
    {
        temp[i]=a[i];
    }

    for (int i = 0; i < size-shift; i++)
    {
        a[i]=a[shift+i];
    }

    int counter=0;
    for(int i=size-shift; i<size; i++)
    {
        a[i]=temp[counter];
        counter++;
    }
}


int main() {
    int n, shift;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the shift no: ";
    cin >> shift;

    rotate(arr, n, shift);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<endl;
    }
}