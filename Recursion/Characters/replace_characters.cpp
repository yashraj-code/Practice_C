// Replace Character Recursively
// Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
// Do this recursively.

#include<iostream>

using namespace std;

void replace(char a[],int size, char c1, char c2)
{
    //base case
    if(a[0]=='\0') {return;}
    
    if(a[0]!='\0')
    {
        if(a[0]==c1)
            {a[0]=c2;}
        
        replace(a+1,size-1,c1,c2);
    }
}



int len_string(char str[])
{
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
    int size = len_string(str);

    char c1,c2;
    cout<<"element to be replaced -> ";
    cin>>c1;
    cout<<"replacement -> ";
    cin>>c2;
    
    replace(str,size,c1,c2);
    
    for(int i=0;i<size;i++)
        cout<<str[i];


}