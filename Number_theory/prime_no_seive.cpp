#include<iostream>

using namespace std;

// need a boolean vector

int makeSieve(int n)
{
    // create a boolean array to store True/False
    // (n+1) is to accommodate 0 as well
    bool isPrime[n+1];
    // we will initialize complete array as true
    for(int i=0;i<=n;i++)
        {isPrime[i] = true;}
    // False will be the one which is not prime

    //set 0 & 1
    //start from 2

    isPrime[0]=false;
    isPrime[1]=false;

    // i<sqrt(n)  ---> i*i < sqrt(n)

    for(int i=2;i*i<n;i++)
    {
        if(isPrime[i]==true)
        {
            // j=i*i because of it is already taken care
            // think about example of 3,6
            for(int j=i*i ;j<=n ; j=j+i)
                {isPrime[j]=false;}
        }
    }

    // now you just need to count no of TRUE
    int count=0;
    for(int i=0;i<=n;i++)
    {
        if(isPrime[i] == true)
            {count++;}
    }

    return count;
}


int main(){
	int n;
	cin >> n;

	int nPrimes = makeSieve(n);
	cout<<nPrimes <<endl;
	return 0;
}