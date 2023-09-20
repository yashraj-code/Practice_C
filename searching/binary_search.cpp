#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int binarysearch(int a[], int left, int right, int key)
{
    while(left<=right)
    {
        int mid = (left+right)/2;
        if(a[mid]<key)
            {left=mid+1;}
        
        else if (a[mid]>key)
            {right=mid-1;}
        
        else
        {//case where a[mid]==key
        return mid;}
    }
    return -1;
}

int main()
{
    int a[]={11,25,36,44,55,56,87,88,99};
    int size=9;
    int search_element = 44;
    int index = binarysearch(a, 0, size-1, search_element);

    cout<<"Index of "<<search_element<<" is -> "<<index;
}