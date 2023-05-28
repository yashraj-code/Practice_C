//BASICS OF REFERENCE

#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int a=10;

    // r is also now a alias of 'a'
    int &r=a;


    int b=30;
    r=b;

    // INTIALLY A==R
    // NOR A==R==B

    // SO ALL ARE UPDATED TO VALUE B
    cout<<a<<endl<<r<<endl;
    
    }

    //OUTPUT= 30
    //        30