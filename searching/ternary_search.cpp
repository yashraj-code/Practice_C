/*
In binary search, the sorted array is divided into two parts while in ternary search, 
it is divided into 3 parts and then you determine in which part the element exists.

[START TO MID1]
[MID1 + 1 TO MID2 -1]
[MID2 TO END]

complexity = log3(N)

use->
This concept is used in unimodal functions to determine the maximum or minimum value of that function. 
Unimodal functions are functions that, have a single highest value.

Let us consider a function FUNC in the interval [A,B], and you are required to determine the [X] for which FUNC(X) is maximized. 
The function FUNC is unimodal in nature, 
i.e. it strictly increases in the interval [A,X] and strictly decreases in the interval[X,B].

*/

#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int ternarysearch(int a[], int left, int right, int key)
{
    while(left<=right)
    {
        int mid1 = left + (right-left)/3;
        int mid2 = right - (right-left)/3;

        if(a[mid1]==key)
        {return mid1;}

        else if (a[mid2]==key)
        {return mid2;}

        //1st half
        else if (a[mid1]>key)
        {right=mid1-1;}

        //3rd half
        else if (a[mid2]<key)
        {left=mid2+1;}

        //2nd half
        else
        left =  mid1 + 1;
        right = mid2 - 1;
    }
    return -1;
}

int main()
{
    int a[]={11,25,36,44,55,56,87,88,99};
    int size=9;
    int search_element = 44;
    int index = ternarysearch(a, 0, size-1, search_element);

    cout<<"Index of "<<search_element<<" is -> "<<index;
}