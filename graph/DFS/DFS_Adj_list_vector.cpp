// DFS , directed, using adjacency list , using vector representation
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(vector<int>*adj, int SourceNode, vector<bool> &visited)
{
	visited[SourceNode]=true;
	cout<<SourceNode<<" ";

	for(auto neighbour:adj[SourceNode])
	{
		if(!visited[neighbour])
			{dfs(adj,neighbour,visited);}
	}
}

void addEdge(vector<int> *adj, int u, int v)
{
	adj[u].push_back(v);
}

int main()	
{
	int vertices = 7;

	vector<int> *adj = new vector<int> [vertices];
	vector<bool>visited (vertices,false);

	addEdge(adj,0,1);
	addEdge(adj,1,2);
	addEdge(adj,2,3);
	addEdge(adj,3,5);
	addEdge(adj,5,6);
	addEdge(adj,4,5);
	addEdge(adj,0,4);
	addEdge(adj,3,4);
	dfs(adj,1,visited);
	return 0;
}