#include<iostream>
#include<list>
using namespace std;

class Graph
{
    int V;
    // liist -> doubly linked list
    //pointer to arrray of lists
    list<int> *l;       // for dynamic mmemory allocation

public:
    Graph(int v)
    {
        V=v;
        l= new list<int>[V];    // size of linked list iv V
        // we will have array of Size V and each block is a linkedlist (L[0],L[1],...L[v-1])

        // overall this means 
        // list<int>* l = new list<int>[V]
    }

    void addEdge(int i, int j, bool undir=true)
    {
        /*
        suppose 1 is connect to 2, then 

        for i=1 , we will insert 2 
        for j=2 , we will insert 1
        */

        l[i].push_back(j);
        
        // if its undirectional then only
        if(undir)
            {l[j].push_back(i);}
    }

    void PrintAdjList()
    {
        // iterate over all the rows
        for(int i=0; i<V; i++)
        {
            cout<<i<<"--> ";
            //every element of the ith linked list

            for(auto node:l[i])
                {cout<<node<<" ";}
            cout<<endl;
        }
    }
};


int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.PrintAdjList();

    return 0;
}
