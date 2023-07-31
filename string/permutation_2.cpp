//Given a string S, find and return all the possible permutations of the input string

// we will get a list of strings,
    // we will need how many elements are there to iterate in the templist as well as in output list
//need to iterate on it
// with first element , iterate with first element with all the positions

#include<iostream>
#include<string>

using namespace std;

int permutation(string str, string output, int temp_size)
{
    //base case
    if(str.empty())
    {
        return;
    }

    outputsize = permutation(str+1, output , 0)

    for(int i=0;i<temp_size;i++)
    {
        str_temp = temp[i];
        for(int j=0;j<str_temp.size()+1 ; j++)
        {
            output[outputsize+j]=str_temp.substring(0,j)+str[0]+str_temp.substring(j+1);
        }
        outputsize=outputsize+str_temp.size()+1
    }

    return outputsize

}



int main()
{
    string str;
    cin>>str;

    string* output = new string[1000];

    permutation(num, output);

    cout << "Result:" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }

    delete[] output; // Free the dynamically allocated memory


    return 0;
}