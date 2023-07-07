#include<iostream>

using namespace std;

int len_string(char str[])
{
    // if there is null character at the starting of the string (empty string)
    if(str[0]=='\0')    {return 0;}

    int ans= 1+len_string(str+1);
    return ans;
}

int main ()
{
    //to give space for null character
    char str [100];
    cout<<"Enter string-> ";
    cin>>str;

    int ans=len_string(str);
    cout<<ans;
}
