/*Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, 
you need to convert the string into corresponding integer 
and return the answer.*/

#include<iostream>
#include<cmath>
using namespace std;


int convert(char str[],int size)
{
    //base case
    if(str[0]=='\0')
    {return 0;}

    // 48 is ascii of 0
    // int(character) will return its ascii value
    int n= int(str[0])- 48;
    int ans = n * pow(10,size-1);
    int temp=convert(str+1,size-1);
    return(temp+ans);
}


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

    int length=len_string(str);
    cout<<str<<endl;
    
    cout<<convert(str,length);
}
