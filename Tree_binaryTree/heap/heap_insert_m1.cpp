// Insert in Heap
// BY ABDUL BARI SIR

// Explanation in notion if required

//just swap with parents till we don’t get a parent which is greater than the inserted element in the array.

#include <iostream>

using namespace std;
 
// n is the position of new element
void InsertA(int A[], int n)
{
	// we
    int i = n;
    int temp = A[n];

	// i>0 so that it doesn't go outside of array
	// compare value at temp and parent and check if temp > parent
	// (i/2)-1 -> for odd and i/2 -> for even
    while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2])
	{
		// swap
        A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];

		// new value of i
        i = i % 2 == 0 ? (i/2)-1 : i/2;
    }

	// after the position is decided insert element there
    A[i] = temp;
}
 
int main() 
{
 
    int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    InsertA(a, 9);
    cout << endl;
 
    return 0;
}