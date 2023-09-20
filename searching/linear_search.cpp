#include <bits/stdc++.h>
#include<iostream>

using namespace std;


int linearsearch(int a[], int search_element,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==search_element)
        {
            return i;
        }
    }
    //if nothing is found
    return -1;
}

int main()
{
    int a[]={11,25,36,44,55,56,87,88,99};
    int size=9;
    int search_element = 44;
    int index = linearsearch(a, search_element,size);

    cout<<"Index of "<<search_element<<" is -> "<<index;
}