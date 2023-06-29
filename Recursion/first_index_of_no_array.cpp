/*Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
*/

#include<iostream>

using namespace std;

int check(int *a,int size,int to_find)
{
    //base case
    if(size==0){return -1;}
    if(*a==to_find) {return 0;}

    //as we are passing a+1, so in next iteration 2nd element of orinial array will be 1st here,
    // we need to add +1 in every iteration

    int ans=1+check(a+1,size-1,to_find);

    //edge case will be -1 when element is not found
    // because it will add +1 everytime;
    
    //only possible if check returns -1
    if(ans==0) {return -1;}
    else {return ans;}
}

int main()
{
    int size,to_find;
    cout<<"Enter size-> ";
    cin>>size;

    int* a= new int[size];
    cout<<"Enter elements\n";
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }

    cout<<"Enter Element to find"<<endl;
    cin>>to_find;

    cout<<check(a,size,to_find)<<endl;
    delete[] a;
}