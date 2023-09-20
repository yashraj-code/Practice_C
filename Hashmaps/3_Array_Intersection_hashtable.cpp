/*
You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular value 
or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements. (print duplicate if it has same duplicate pair in 2nd array)

The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).

Sample Input 1 :
2
6
2 6 8 5 4 3
4
2 3 4 7 
2
10 10
1
10

Sample Output 1 :
2 3 4
10

Sample Input 2 :
1
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 2 2
*/

/*
Approach using hashtables ->
- completely make pair sets from one array
    - if the key is repeating increase its value (for duplicates)
- Iterate over 2nd array
    - if key is present -> insert in vector
    - if that keys. value is 1 remove it (handle duplicates)
    - else decrease by 1

*/



#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> intersection(int *a,int size1, int *b,int size2)
{
    vector<int> output;
    unordered_map<int,int> seen;
    for (int i=0;i<size1;i++)
    {
        if(seen.count(a[i])==0)
            {
            //does not exist
            seen[a[i]]=1;
            }
        else
            {seen[a[i]]=seen[a[i]]+1;}
    }

    for (int i=0;i<size2;i++)
    {
        if(seen.count(b[i])!=0)
        {
            // means a match is there
            output.push_back(b[i]);

            // for duplicates
            //remove this pair
            //else decrease the value by 1
            if(seen[b[i]]==1)
                {seen.erase(b[i]);}
            else
                {seen[b[i]]=seen[b[i]]-1;}
        }
    }
    return output;
}


int main()
{
int test;
cout<<"No of test cases -> ";
cin>>test;

while(test-->0)
{
    int size1,size2;
    cout<<"Enter size of Array 1 -> ";
    cin>>size1;

    int a[size1];
    for(int i=0; i<size1; i++)
        {cin>>a[i];}
        

    cout<<"Enter size of Array 2 -> ";
    cin>>size2;

    int b[size2];
    for(int i=0; i<size2; i++)
        {cin>>b[i];}

    vector<int> output = intersection(a,size1,b,size2);

    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<" ";
    }
}

}