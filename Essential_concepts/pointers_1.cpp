// C++ program to illustrate Pointers
  
#include <bits/stdc++.h>
using namespace std;
void geeks()
{
    int var = 20;
  
    // declare pointer variable
    int* ptr;
  
    // note that data type of ptr and var must be same
		// storing address of 'a' in 'p'
    ptr = &var;
  
    // assign the address of a variable to a pointer
    cout << "Value at ptr = " << ptr << "\n";
    cout << "Value at var = " << var << "\n";

		// printing value stored a at address p
    cout << "Value at *ptr = " << *ptr << "\n";
}
// Driver program
int main() 
{ 
  geeks(); 
  return 0;
}