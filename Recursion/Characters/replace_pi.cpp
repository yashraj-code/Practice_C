
/*Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Sample Input 1 : xpix
Sample Output :  x3.14x
*/
#include<iostream>

using namespace std;

void replace_pi(char str[], int size)
{

    // as we are also checking one element further
    if(str[0]=='\0')
    {return;}

    if(str[0]=='p' && str[1]=='i')
    {
        // shifting elements to right
        // starting from last element
        for(int i=size;i>=2;i--)
            {str[i+2] =str[i];}

        str[0]='3';
        str[1]='.';
        str[2]='1';
        str[3]='4';

        replace_pi(str+4,size-2);
    }
    else 
    {
        replace_pi(str+1,size-1);
        
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

    replace_pi(str,length);
    length=len_string(str);

    for(int i=0;i<length;i++)
    {
        cout<<str[i];
    }
}
