#include<iostream>
#include<vector>

using namespace std;

void addEdge(vector<int> *adj, int u, int v, bool undir=true)
{
    adj[u].push_back(v);

    // if(undir)
    //     {adj[v].push_back(u);}
}

void print(vector<int> *adj, int vertice)
{
    for(int i=0;i<vertice;i++)
    {
        cout<<i<<"--> ";
        for(auto j:adj[i])
            {cout<<j<<" ";}
        
        cout<<endl;
    }
}

int main()
{
    int vertice = 5;

    //create a pointer to vector
    vector<int> *adj= new vector<int>[vertice];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    print(adj,vertice);
}