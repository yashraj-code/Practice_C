// print connected components in an undirected graph using DFS
// adjacency list representation
#include<iostream>
#include<list>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph 
{
	int V; // No. of vertices

	// Pointer to an array containing adjacency lists
	list<int>* l;

public:
	Graph(int v) // Constructor
    {
        V=v;
        l=new list<int>[V];     // size of linked list iv V
    }

    // method to add an undirected edge
    void addEdge(int i, int j)
    {
        l[j].push_back(i);
        l[i].push_back(j);
    }

    void DFSUtil(int node, bool visited[])
    {
	// Mark the current node as visited and print it
	visited[node] = true;
	cout << node << " ";

	// iterate over every element in that NODE-connection.
	// this function will finally end when all the connections have been visited

		for(auto neigh: l[node])
		{
			if (!visited[neigh])
				{DFSUtil(neigh, visited);}
		}
	}

	// Method to print connected components in an undirected graph
	void connectedComponents()
	{
		// Mark all the vertices as not visited
		bool* visited = new bool[V]{0};

		// we will iterate on all theunvisisted vertices
		for (int vertice = 0; vertice < V; vertice++) {
			if (visited[vertice] == false) 
			{
				// print all reachable vertices
				// from vertice
				DFSUtil(vertice, visited);
				cout << "\n";
			}
		}
		delete[] visited;
	}

};

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g(5); // 5 vertices numbered from 0 to 4
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(3, 4);

	cout << "Following are connected components \n";
	g.connectedComponents();

	return 0;
}
