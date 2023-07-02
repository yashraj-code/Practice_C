#include<iostream>
#include<cstring>

using namespace std;

bool pallindrome(int start,char c[],int end)
{
    bool ans;
    //edge case
    if(end==1)  {return true;}
    
    //base case
    // if (start<=end) {return true;}
    if(start==end)  {return true;}
    
    //condition
    if(c[start]!=c[end])    {return false;}
    
    //recursive call
    ans=pallindrome(start+1,c,end-1);

    return ans;
}

int main()
{
    int size;
    cout<<"Enter size -> ";
    cin >> size;

    //to give space for null character
    char str [size+1];
    cout<<"Enter string-> ";
    cin>>str;

    bool ans=pallindrome(0,str,size-1);

    cout<<"Ans -> "<<ans;
}