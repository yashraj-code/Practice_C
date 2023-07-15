/*Return all the subsequences of the string ->> abc
a,b,c,ab,ac,bc,abc,""   -> 8 sub sequence

string of length n will have 2^n substrings

Suppose we have ["", b, c , bc]
we only need to copy all the elements  + add a in all the elements of this array
[a , ab ,ac ,abc] + ["", b, c , bc]
so then there will be total 8 elements

*/


# include <iostream>
# include <string>

using namespace std;

// It will traverse till last element
// First "" is entered which will be input[0]
// this is added to last letter that returns


int sub_sequence(string input , string output[])
{
    //base case
    if(input.empty())
    {
        output[0]="";
        return 1;
    }

    // returns whole string except 0th element
    string samllString = input.substr(1);
    int smallOutputSize = sub_sequence(samllString,output);

    // we iterate till this as we need to add that one element
    // to all the memebers of array
    for(int i=0;i<smallOutputSize;i++)
    {
        output[i+smallOutputSize] = input[0]+output[i];
    }

    // as elements in array are now doubled
    return 2*smallOutputSize;

}

int main()
{
    cout<<"Enter String -> "
    string input;
    cin>>input;

    // We create a dynamic array of strings for smooth operations 
    string* output = new string[1000];

    // this will give us the count of elements present in it
    // we need this because we have created output array dynamically
    // we don't know how many elements were inserted

    int count = sub_sequence(input,output);

    // print all the elements of array
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }

}