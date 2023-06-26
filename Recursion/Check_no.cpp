// Given an array of length N and an integer x, 
// you need to find if x is present in the array or not. 
// Return true or false.

#include<iostream>

using namespace std;

bool check_no(int a[],int size,int find)
{
    //base case
    if(size==0){return false;}
    
    if(a[0]==find){return true;}

    bool ans=check_no(a+1,size-1,find);
    return ans;
}

int main()
{
    int len,find;
    cout<<"enter size-> "; 
    cin>>len;
    int a[len];

    for (int i=0;i<len;i++)
    {
        cin>>a[i];
    }
    cout<<"Element to find";
    cin>>find;

    bool ans=check_no(a,len,find); 
    cout<<ans;

}