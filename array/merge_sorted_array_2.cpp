#include <bits/stdc++.h>
using namespace std;

vector<int> mergeTwoPointers(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    // Merge elements in sorted order
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j])
            merged.push_back(arr1[i++]);
        else
            merged.push_back(arr2[j++]);
    }

    // Add remaining elements from either array
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);

    return merged;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> merged = mergeTwoPointers(arr1, arr2);

    for (int num : merged) cout << num << " ";  // Print merged array
    return 0;
}