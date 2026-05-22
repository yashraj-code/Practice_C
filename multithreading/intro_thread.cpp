// find the sum of even and odd numbers from 1 to 1.9 billion using multithreading in C++

#include<iostream>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum=0;
ull EvenSum=0;

void findEven(ull start, ull end)
{
    ull localSum = 0; // Kept entirely in a CPU register (reason given below)
    for(ull i=start; i<=end; i++)
    {
        if(i%2==0)
            localSum += i;
    }
    EvenSum = localSum; // Updates shared memory exactly ONCE
}

void findOdd(ull start, ull end)
{
    ull localSum = 0;
    for(ull i=start; i<=end; i++)
    {
        if(i%2!=0)
            localSum += i;
    }
    OddSum = localSum; // Updates shared memory exactly ONCE
}

// Here main will have a master thread which will create two child threads
int main()
{
    ull start=1, end=1900000000;
    auto startTime=high_resolution_clock::now();

    // Create two threads to find the sum of even and odd numbers
    // syntax: thread t1(function, arguments);

    thread t1(findEven, start, end);
    thread t2(findOdd, start, end);

    // this will take 7000 milliseconds to execute
    // findEven(start, end);
    // findOdd(start, end);
    
    // Wait for the threads to finish
    // if we will not join the threads then as soon as the main thread finishes its execution the child threads will be terminated
    // so we need to join the threads to make sure that the main thread waits for the child threads to finish their execution before it terminates

    //this will take 3000 milliseconds to execute
    t1.join();
    t2.join();

    auto endTime=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(endTime-startTime).count();

    cout<<"Sum of even numbers: "<<EvenSum<<endl;
    cout<<"Sum of odd numbers: "<<OddSum<<endl;
    cout<<"Time taken: "<<duration<<" milliseconds"<<endl;

    return 0;
}


/*
Suppose we write the code without using localSum and directly update the shared memory variable inside the loop 
then it will cause a lot of cache misses and it will take a lot of time to execute (Cache Ping-Pong)
this method was taking 35000 milliseconds to execute on my machine, which is too slow
compared to single-threaded version which was taking 7000 milliseconds to execute.

void findEven(ull start, ull end)
{
    for(ull i=start; i<=end; i++)
    {
        if(i%2==0)
            EvenSum += i; // Updates shared memory on every iteration
    }
}

Reason:

CPUs do not read variables from main memory (RAM) one byte at a time. 
They fetch memory in chunks called Cache Lines (usually 64 bytes).

Because these are declared right next to each other, they are packed into the exact same 64-byte cache line in the CPU's cache.

Here is the sequence of events when you use threads:

    Core 1 (running findEven) pulls the cache line into its L1 cache and updates EvenSum.
    Because the cache line was modified, the hardware flags that entire 64-byte block as "invalid" for all other CPU cores.

    Core 2 (running findOdd) wants to update OddSum. Even though it doesn't care about EvenSum, they share the same cache line.
    Core 2 experiences a "cache miss," forcing it to pause, go all the way out to main memory, and fetch the newly updated cache line.
    Core 2 updates OddSum. This invalidates the cache line for Core 1.

    Core 1 now experiences a cache miss and has to fetch from RAM.

OUR loop runs 1.9 billion times. This means your two CPU cores are invalidating each other's cache billions of times per second. 
This "cache ping-pong" is incredibly slow compared to a single thread that just owns the cache line exclusively.

The golden rule of multithreaded performance is to minimize writes to shared memory.

Instead of writing to the global EvenSum and OddSum inside the loop, accumulate the sum in a local variable. 
Local variables are stored in the CPU's blazing-fast internal registers. 
Once the loop is done, write the final result to the global variable once.

*/