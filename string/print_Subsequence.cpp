/*print all the subsequences of the string ->> abc
a,b,c,ab,ac,bc,abc,""   -> 8 sub sequence
*/

// full explanation in notion

# include <iostream>
# include <string>

using namespace std;

// It will traverse till last element
// First "" is entered which will be input[0]
// this is added to last letter that returns


void print_sub_sequence(string input , string output)
{
    //base case
    if(input.empty())
    {
        cout<<output<<endl;
        return ;
    }

    print_sub_sequence(input.substr(1),output);
    print_sub_sequence(input.substr(1),output+input[0]);
}

int main()
{
    cout<<"Enter String -> ";
    string input;
    cin>>input;
    
    string output = "";
    
    print_sub_sequence(input,output);
}