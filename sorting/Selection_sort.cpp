#include <iostream>

using namespace std;

void selection_sort(int a[], int size)
{
    // temporary variable to the store the position of minimum element
    int min;
    
    for(int i=0;i<size-1;i++)
    {
        min=i;
        for(int j=i+1;j<size;j++)
        {
            //if other element is minimum then take its index
            if(a[i]>a[j])
            {
                min=j;
            }
        }

        // Putting minimum element in its proper position
        //swap the elements
        int temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}

int main()
{
    int size;
    cout<<"no of elements"<<endl;
    cin>>size;
    
    int a[size];
    cout<<"Enter Elements";

    for(int i=0;i<size;i++)
        cin>>a[i];

    selection_sort(a,size);

    for (int i=0;i<size;i++)
        cout<<a[i]<<" ";
}