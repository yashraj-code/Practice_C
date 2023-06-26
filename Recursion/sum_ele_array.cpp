// Given an array of length N, you need to find and return the sum of all elements of the array.
// Do this recursively.


// we will use a+1 to pass next part of the array recursively

#include<iostream>

using namespace std;

int sum_array(int a[],int size)
{
    //base case
    if(size==0){return 0;}

    //a[n] = a[0]+a[n-1]
    int temp_sum = a[0]+sum_array(a+1,size-1);
    return temp_sum;
}
 
int main()
{
    int size;
    cout<<"enter size-> ";
    cin>>size;
    int a[size];

    for (int i=0;i<size;i++)
    {
        cin>>a[i];
    }

    int ans=sum_array(a,size);
    cout<<ans;

}