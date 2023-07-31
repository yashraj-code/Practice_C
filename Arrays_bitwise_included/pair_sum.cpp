/*

Given an unsorted array and a no -> Find the all the pairs which add upto that a given no

solution1 ->
pick first element iterate throught the array to find sum==num
then with 2nd element etc

complexity -O(n2)

solution 2->

lets think if sorting will help or not
complexity-> O(nlogn)

now when we have a sorted array
Approach - 2 pointer

staring i=0; j=end

if(i+j)>num, then as i is least, means j is large for the sum, so  j--
if(i+j)<num, then as j is max , means i is very samll, needs to increase, i++
and if i==j , means no pair was found
complexity -> ()

Problem
with this method is that i cant handle duplicates.
incase of 2,2,2,2,2
the output shoul be 4+3+2+1 = 10

for this you can count if the same no in pair is occuring one or more time, then add accordingly
1334589915, sum=12

then (3,9) = 2times*3times =6 pairs
(4,8)
total = 7
*/

#include <iostream>
#include<string>

using namespace std;

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {

  int pivot = array[high];

  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) 
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) 
{
  if (low < high)
  {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


int pair_sum(int a[], int size, int sum) {
    int count = 0;
    int i = 0;
    int j = size - 1;

    while (i < j) {
        if (a[i] + a[j] > sum) 
          {j--;} 
        else if (a[i] + a[j] < sum) 
          {i++;} 
        else 
        {
            int left_count = 1;
            int right_count = 1;

            // Count duplicates on the left
            while (i + 1 < j && a[i] == a[i + 1]) 
            {
                i++;
                left_count++;
            }

            // Count duplicates on the right
            while (j - 1 > i && a[j] == a[j - 1]) 
            {
                j--;
                right_count++;
            }

            // Count the pairs with the duplicates
            count += (left_count * right_count);

            i++;
            j--;
        }
    }

    return count;
}


int main()
{
    int size,sum;
    cout<<"no of elements"<<endl;
    cin>>size;
    
    int a[size];
    cout<<"Enter Elements";

    for(int i=0;i<size;i++)
        cin>>a[i];

    cout<<'Enter sum';
    cin>>sum;

    quickSort(a,0,size-1);
    cout<<pair_sum(a,size,sum)<<endl;
