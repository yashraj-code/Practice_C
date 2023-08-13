/*
Given an integer n, 
using phone keypad find out all the possible strings 
that can be made using digits of input n.
Return empty string for numbers 0 and 1.
*/
#include<iostream>
#include<string>

using namespace std;

string getString(int n)
{
    switch (n)
    {
    case 2: return "abc";
    case 3: return "def";
    case 4: return "ghi";
    case 5: return "jkl";
    case 6: return "mno";
    case 7: return "pqrs";
    case 8: return "tuv";
    case 9: return "wxyz";
    default: return "";
    }
}

int check(int num, string output[])
{
    // base case
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }

    int n = num % 10;
    num = num / 10;

    int smallOutputSize = check(num, output);
    string str = getString(n);
    int charCount = str.size();

    // Temporary array to store the new combinations
    string* temp = new string[1000];
    int tempSize = 0;

    // Generating combinations using two characters at a time
    for (int i = 0; i < smallOutputSize; i++)
    {
        for (int j = 0; j < charCount; j++)
        {
            temp[tempSize++] = output[i] + str[j];
        }
    }

    // Copy the combinations from the temporary array to the output array
    for (int i = 0; i < tempSize; i++)
    {
        output[i] = temp[i];
    }

    delete[] temp; // Free the dynamically allocated memory

    return charCount * smallOutputSize;
}

int main()
{
    int num;
    cout << "Enter a number (0 and 1 will result in an empty string): ";
    cin >> num;

    if (num == 0 || num == 1)
    {
        cout << "Result: " << endl; // Empty string for 0 and 1
    }
    else
    {
        string* output = new string[1000];
        int count = check(num, output);

        cout << "Result:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << output[i] << endl;
        }

        delete[] output; // Free the dynamically allocated memory
    }

    return 0;
}
