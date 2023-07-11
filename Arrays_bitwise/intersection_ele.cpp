// Given two random integer arrays, print their intersection. 
// That is, print all the elements that are present in both the given arrays.
// Input arrays can contain duplicate elements.


// Method 1
// Pick one element from one array
// check it in other array


// Method 2 
// sort one array and from other array elements apply binary search on sorted one

// Method 3 
// using sorting and 2 pointers
//  sort both the arrays and use two pointers as shown below


#include<iostream>

using namespace std;


void intersection(int a[],int b[], int sa,int sb)
{
    int i,j;
    
    while (i <sa && j <sb)
    {
        if(a[i]==b[j])
        {
            cout<<a[i];
            i++;
            j++
        }
        else if (a[i]<b[j])
        {
            //increase i
            i++;
        }
        else
        {
            j++;
        }
    }
}


void merge(int arr[],int start,int mid,int end)
{
    //temporary variables as we are going to iterate over it
    int p=start;
    int q=mid+1;

    //size of the temp array
    int temp[end-start+1];
    // to track how many elements we have inserted
    int k=0;

    // as with p we will go till mid
    // with q we will go till end
    // if one finishes early just copy whatever is left
    while(p<=mid && q<=end)
    {
        if(arr[p] > arr[q])
            temp[k++]=arr[q++];   // it is a post increment op, value is used first then increased
        
        else
            temp[k++]=arr[p++];
    }

    // insert whatever is left
    // That sub Array is already sorted

    // as left part is smaller s that first
    while (p<=mid)
        temp[k++]=arr[p++];
    
    while (q<=end)
        temp[k++]=arr[q++];


    // copying to the original array

    for(int i=0;i<k;i++)
        {arr[start++]=temp[i];}
} 



//for breaking the array
void mergeSort(int a[],int start,int end)
{
    //base case
    // only at equal we are sure that it is single element now (1=1)
    // It will run till that point, till 1!=1
    if(start<end)
    {
        int mid = (start+end)/2;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a, start, mid,end);
    }
}


int main()
{
    int size1;
    cout<<"enter size of 1st array";
    cin>>size1;
    
    int arr1[size1];
    cout<<"Enter Elements "<<endl;
    for(int i=0;i<size1;i++)
    {
        cin>>arr1[i];
    }

    cout<<"enter size of 2nd array";
    int size2;
    cin>>size2;
    
    int arr2[size2];
    cout<<"Enter Elements "<<endl;
    for(int i=0;i<size2;i++)
    {
        cin>>arr2[i];
    }

    // we want to pass sorted aaray
    mergeSort(arr1,0,size1-1);
    mergeSort(arr2,0,size2-1);

    intersection(arr1,arr2,size1,size2);
}