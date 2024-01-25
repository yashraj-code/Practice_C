#include<iostream>

using namespace std;


int countSubsetSum(int set[],int n,int sum)
{
    if(sum==0 && n==0)
        return 1;

    if(sum==0)
        {return 1;}
    
    if(n==0)
        return 0;
    
    // when including
    if(sum-set[n-1]>=0)
    {
        return countSubsetSum(set,n-1,sum-set[n-1]) + countSubsetSum(set,n-1,sum);
    }
    else
    {
        return countSubsetSum(set,n-1,sum);
    }
}

int main()
{
    int set[] = { 1,2,3,3 };
    int sum = 6;
    int n = sizeof(set) / sizeof(set[0]);
    int ans = countSubsetSum(set, n, sum);
    cout<<"Ans -> "<<ans;

    return 0;
}