#include<iostream>

using namespace std;

int main()
{
    int rows, column;
    cin>>rows>>column;

    // double pointer to store pointer to array of pointers
    int **p = new int*[rows];
    // array of pointers is made to store all the pointers of the rows created further

    for(int i=0;i<rows;i++)
    {
        p[i]= new int[column];

        for(int j=0;j<column;j++)
        {
            cin >>p[i][j];
        }
    }
    // values can be accessed freely via p[4][5]

    //to de-allocate
    for(int i=0;i<rows;i++)
    {
        delete [] p[i];         //first de allocate all the rows
    }

    delete [] p;  // de allocate pointer array at last, as it stores memory location of all the rows
}