#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<int> *adjlist, int startNode, vector<bool> &visited, vector<vector<int>> &ans)
{
	queue<int> Que;
	Que.push(startNode);
	visited[startNode]=true;

	while(!Que.empty())
	{
		int level_size = Que.size();
		vector<int>level;
		for(int i=0; i<level_size; i++)
		{
			int node = Que.front();
			Que.pop();
			level.push_back(node);

			for(auto neighbour:adjlist[node])
				{
					if(visited[neighbour]==false)
					{
						Que.push(neighbour);
						visited[neighbour]=true;
					}
				}
		}
		ans.push_back(level);
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

	// store levels
	vector<vector<int>> ans;

	// Perform BFS traversal starting from vertex 0
	cout << "Breadth First Traversal starting from vertex "
			"0: "<<endl;
	bfs(adjList, 0, visited, ans);

	for(auto i:ans)
	{
		for(auto j:i)
			{cout<<j<<",";}
		cout<<endl;
	}
	return 0;
}
