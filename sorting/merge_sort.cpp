#include<iostream>

using namespace std;


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
    int size;
    cout<<"no of elements"<<endl;
    cin>>size;
    
    int a[size];
    cout<<"Enter Elements";

    for(int i=0;i<size;i++)
        cin>>a[i];

    mergeSort(a,0,size-1);

    for (int i=0;i<size;i++)
        cout<<a[i]<<" ";
}