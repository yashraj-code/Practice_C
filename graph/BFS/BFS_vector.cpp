#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<int> *adjlist, int startNode, vector<bool> visited)
{
	queue<int> Que;
	Que.push(startNode);
	visited[startNode]=true;

	while(!Que.empty())
	{
		int node = Que.front();
		Que.pop();

		cout<<node<<" ";

		for(auto neighbour:adjlist[node])
			{
				if(visited[neighbour]==false)
				{
					Que.push(neighbour);
					visited[neighbour]=true;
				}
			}
	}
}

// Function to add an edge to the graph
void addEdge(vector<int> *adjList , int u, int v, bool undir=true)
{
	adjList[u].push_back(v);

	if(undir)
		{adjList[v].push_back(u);}
}

int main()
{
	// Number of vertices in the graph
	int vertices = 5;

	// Adjacency list representation of the graph
	vector<int> *adjList = new vector<int> [vertices];

	// Add edges to the graph
	addEdge(adjList, 0, 1);
	addEdge(adjList, 0, 2);
	addEdge(adjList, 1, 3);
	addEdge(adjList, 1, 4);
	addEdge(adjList, 2, 4);

	//visited vector
	vector<bool> visited(vertices,false);

	// Perform BFS traversal starting from vertex 0
	cout << "Breadth First Traversal starting from vertex "
			"0: ";
	bfs(adjList, 0, visited);

	return 0;
}
