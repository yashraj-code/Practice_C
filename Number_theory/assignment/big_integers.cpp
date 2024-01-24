#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

char digit_to_char(int digit)
    {return digit+'0';}

int char_to_digit(char ch)
    {return ch-'0';}

string add_no(string n1,string n2)
{
    //make sure the 2nd string is the larger one
    if(n1.length() > n2.length())
        {swap(n1,n2);}
    
    string result = "";

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    int carry =0;

    // lets add till n1 first
    for(int i=0;i<n1.size();i++)
    {
        int d1 = char_to_digit(n1[i]);
        int d2 = char_to_digit(n2[i]);
        int sum = d1+d2+carry;
        int res = sum%10;
        carry = sum/10;
        result.push_back(digit_to_char(res));
    }
    // till here we have done everything where both the strings digits are present

	// now we need to add what ever is left

	for(int i=n1.size(); i<n2.size(); i++)
	{
		int d2 = char_to_digit(n2[i]);
		int sum = d2 + carry;
		int res = sum %10;
		carry = sum/10;
		result.push_back(digit_to_char(res));
	}

	//edge case if carry is still left
	if(carry == 1)
		{result.push_back('1');}
	
	// reverse the final list
    reverse(result.begin(), result.end());
	return(result);

}

int main()
{
	string s1, s2;
	cin>>s1>>s2;
	string result = add_no(s1,s2);

	cout<<result<<endl;
}