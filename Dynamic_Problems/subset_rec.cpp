#include<iostream>

using namespace std;


bool isSubsetSum(int set[],int n,int sum)
{
    // base case
    // if size of array -> 0 and sum = 0;
    // then true rest all will be false

    //this first so that condition is true
    if(sum==0)
        {return true;}
    
    if(n==0)
        {return false;}
    
    //not to include
    if(sum-set[n-1]<0)
    {
        return isSubsetSum(set,n-1,sum);
    }
    else
    {
        return isSubsetSum(set,n-1,sum-set[n-1]) || isSubsetSum(set,n-1,sum);
    }
}

int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}