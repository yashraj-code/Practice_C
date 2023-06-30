/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array.
Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> indices(int *a, int size, int to_find, int index)
{
    // Base case
    if (index == size) 
        { return {}; }

    vector<int> ans = indices(a + 1, size, to_find, index + 1);

    if (*a == to_find) 
        {ans.insert(ans.begin(), index);}

    return ans;
}

int main()
{
    int size, to_find;
    cout << "Enter size -> ";
    cin >> size;

    int* a = new int[size];
    cout << "Enter elements\n";
    
    for (int i = 0; i < size; i++)
        {cin >> a[i];}

    cout << "Enter element to find: ";
    cin >> to_find;

    vector<int> result = indices(a, size, to_find, 0);

    for (int index : result) 
        {cout << index << " ";}
    
    cout << endl;

    delete[] a;
    return 0;
}
