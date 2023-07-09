// C++ program to demonstrate
// Basic Euclidean Algorithm

#include <bits/stdc++.h>
using namespace std;

// Function to return
// gcd of a and b
int gcd(int a, int b)
{
    // as a>b for algo to work
    if(a<b) { return gcd(b,a); }

	if (a == 0)
		return b;
        
	return gcd(b % a, a);
}

// Driver Code
int main()
{
	int a = 10, b = 15;

	// Function call
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	a = 35, b = 10;
	cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
		<< endl;
	return 0;
}
