#include <bits/stdc++.h>
using namespace std;

vector<int> mergeNaive(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result(arr1.begin(), arr1.end());  // Copy first array
    result.insert(result.end(), arr2.begin(), arr2.end());  // Append second array
    sort(result.begin(), result.end());  // Sort the combined array
    return result;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> merged = mergeNaive(arr1, arr2);
    
    for (int num : merged) cout << num << " ";  // Print merged array
    return 0;
}