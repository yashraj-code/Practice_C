// <---------- RECTANGLE EXAMPLE 1 ---------->

#include<stdio.h>
#include<iostream>

using namespace std;

struct rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct rectangle r1 = {10,5}; // DEFAULT VALUE

    r1.length=10;
    r1.breadth=28;

    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;

    return 0;
}