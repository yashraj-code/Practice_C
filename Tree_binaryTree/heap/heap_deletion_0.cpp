// By adbul sir

#include <bits/stdc++.h>
using namespace std;

void Delete(int A[], int n)
{
    int x,i,j;

    //swap the root with the last element
    swap(A[1],A[n]);

    //root position
    i=1;

    //for children (left child)
    j=2*i;

    // n-1 because we have one element less
    while(j<=n-1)
    {
        // to compare left child and right child
        // which ever child is greater point to that
        if(A[j+1]>A[j])
        {
            j=j+1;
        }

        // compare that larger child to root
        if (A[i]<A[j])
        {
            swap(A[i],A[j]);
            // now I will point to the place where swapping took place
            i=j;
            j=2*i;
        }
        else
            {break;}

    }
}