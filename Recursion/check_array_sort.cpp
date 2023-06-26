/* Here we are going to use a very iportatn concept of passing
   part of array, we can pass part of array in recursion by a+1 
*/
#include <iostream>
using namespace std;

bool is_sorted(int a[], int size)
{
    if(size==0 || size==1){return true;}

    if(a[0]>a[1]){return false;}

    bool sorted = is_sorted(a+1,size-1);
    return sorted;
    /*
    if(sorted) {return true;}
    else {return false;}
    */

}