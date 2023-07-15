// Remove Duplicates Recursively
// Given a string S, remove consecutive duplicates from it recursively.
// Sample Input :
// aabccba
// Sample Output :
// abcba

#include<iostream>
using namespace std;

void remove_duplicate(char a[],int size)
{
    if(a[0]=='\0')
        {return;}

    if(a[0]!='\0')
    {
        if(a[0]==a[1])
        {
            //shift all
            for(int i=1;i<=size;i++)
                    {a[i-1]=a[i];}
                    
            remove_duplicate(a,size-1);

        }
    else
        {remove_duplicate(a+1,size-1);}
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
    
    remove_duplicate(str,size);
    
    for(int i=0;str[i]!='\0';i++)
        cout<<str[i];


}