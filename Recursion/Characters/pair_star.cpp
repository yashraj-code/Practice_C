/*Given a string, compute recursively a 
new string where identical chars that are adjacent in the 
original string are separated from each other by a "*".
Input : xxyy
Output : x*xy*y
*/

#include<iostream>

using namespace std;


void pair_star(char str[], int size)
{
    //base case
    if(str[0]=='\0')
    {return;}

    if(str[0]==str[1])
    {
        for(int i=size;i>1;i--)
        {
            a[i+1]=a[i];
        }
        str[1]='*';

        // to skip a* and pass other a
        return(str+2,size-1);
    }
    else
    {
        return(str+1,size-1);
    }

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
    
    cout<<pair_star(str,length);

    length=len_string(str);
    for(int i=0;i<length;i++)
    {
        cout<<str[i];
    }

}
