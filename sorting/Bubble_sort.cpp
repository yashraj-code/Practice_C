#include<iostream>

using namespace std;


void bubble_sort(int a[],int size)
{
    for (int step=0;step<size-1; step++)
    {
        for (int j=0;j<size-step-1; j++)
        {
            // extra -1 because when we are comapring at last postion
            // because it is a[j+1] it is accessing elements outside the array

            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
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

    bubble_sort(a,size);

    for (int i=0;i<size;i++)
        cout<<a[i]<<" ";
}