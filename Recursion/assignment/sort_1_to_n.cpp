#include<iostream>
#include <vector>
using namespace std;

/*
Sort array using recursion

func(array,size) -> we will assume that this function will return us a sorted array

// excluding the last element
func(array,size-1) -> we will assume this also returns us a sorted array

now 
*/
void insert(vector<int> &v, int temp)
{
    //here will check upon where to insert the element temp
    //base condition
    if(v.size()==0 || v[v.size()-1]<=temp)
    {v.push_back(temp); return;}

    // Store the last element and  iterate tillwe dont get favourable condition 
    int val = v[v.size()-1];
    v.pop_back();

    insert(v,temp);
    v.push_back(val); return;
}

void sort(vector<int> &v)
{
    // we will remove each element

    //means everything is sorted, if there is element
    if(v.size()==1)
    {return ;}
    
    // last element we have removed and stored
    int temp = v[v.size()-1];
    v.pop_back();

    sort(v);

    // now we assume sort will give sorted vector
    // where we need to insert whatever is there in temp

    insert(v,temp);
}

int main()
{
    vector <int> arr {1, 6, 12, 3, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    sort(arr);

    for(auto i:arr)
        {cout<<i<<",";}
   

    return 0;
}