// 0 1 1 2 3 5 8
// nth no is sum of its previous 2 no's
// fib(n)=fib(n-1)+fib(n-2)

# include<iostream>
using namespace std;

int fib(int n)
{
    //base case
    if (n == 0) {return 0;}

	if (n == 1) {return 1;}

    int op1=fib(n-1);
    int op2=fib(n-2);
    return op1+op2;
}

int main()
{
    cout<<fib(6)<<endl;
}
