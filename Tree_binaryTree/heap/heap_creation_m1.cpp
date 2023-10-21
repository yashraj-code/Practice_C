// create a heap
// BY ABDUL BARI SIR
/*
- we will assume that there is only one element in the array, 
        the very first element and heap creation starts from it.
        
- one by one we will put elements in right to left using same method we learnt in insertion.
*/

#include <iostream>
#include <vector>

using namespace std;
 
//same as insert function
void InsertInplace(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
    {
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }
    A[i] = temp;
}

// the element to be inserted in heap is passed
void createHeap(int A[], int n)
{
    for (int i=0; i<n; i++)
        {InsertInplace(A, i);}
}
 
int main()
{
 
    cout << "Create Heap" << endl;
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    createHeap(b, sizeof(b)/sizeof(b[0]));
 
    return 0;
}