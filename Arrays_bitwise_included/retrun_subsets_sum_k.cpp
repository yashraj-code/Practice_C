/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.
*/

/*
move in 2 ways ->
we will exclude first element and then also sum=sum , we haven't taken its contribution
we will exclude first element and sum = sum-a[0] , this accounts to condition where we have taken a[0] contribution
*/

#include<iostream>
#include<vector>

using namespace std;

void generate_subset(int arr[], int size, int x, vector<int> vector_1d, vector<vector<int>> &result)
{
    //base case

    if(size == 0)
    {
        if (x == 0)
        {
            result.push_back(vector_1d);
        }
        return; // Add this return statement
    }

    // include its contribution
    vector_1d.push_back(arr[0]);
    generate_subset(arr+1, size-1, x-arr[0], vector_1d, result);


    vector_1d.pop_back();
    // do not include its contribution
    generate_subset(arr+1, size-1, x, vector_1d, result);

}

vector<vector<int>> get_subset(int arr[],int size, int x)
{
    // 2D- vector to contain all the 1D vectors
    vector<vector<int>> result;

    // contains all the 1D vectors
    vector<int> vector_1d;

    generate_subset(arr, size, x, vector_1d, result);

    return result;
}


int main()
{
    int size, x;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> x;

    vector<vector<int>> result = get_subset(arr, size, x);

    int i, j;
    for (i = 0; i < result.size(); i++)
    {
        vector<int> subset = result[i];
        for (j = 0; j < subset.size(); j++)
        {
            cout << subset.at(j) << " ";
        }

        cout << endl;
    }
    
    
}