// to remove a specific character from the array using recursion
// for simplicity it is fixed to 'x' now
// cannot use another array


#include<iostream>

using namespace std;

void removeX(char s[])
{
    if(s[0]=='\0') {return;}

    if(s[0]!='x')  
        {removeX(s+1);}
    else 
    {
        int i=1;        // we used this here not in for because we want its value further also
        //shift all the characters
        for(; s[i]!='\0'; i++)   //null chararcter is right
            {s[i-1]=s[i];}
        
        //to shift null character as well
        s[i-1]=s[i];
        removeX(s);
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
}
