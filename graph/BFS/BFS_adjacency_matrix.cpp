// same problem if there ae disconnected nodes it wont reach nodes
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

// function to add edge to the graph
void addEdge(int x,int y)
{
	adj[x][y] = 1;
	adj[y][x] = 1;
}

// Function to perform BFS on the graph
void bfs(int start)
{
    int n = adj.size();
	vector<bool> visited(n, false);

	queue<int> q;
	q.push(start);

	// Set source as visited
	visited[start] = true;

  while (!q.empty()) {
		int vis = q.front();
      	q.pop();

		// Print the current node
		cout << vis << " ";

		// For every adjacent vertex to the current vertex
        // IMP - Difference lies here that we need i as we need to loop up in matrix 
		for (int i = 0; i < adj[vis].size(); i++) 
        {
			if (adj[vis][i] == 1 && (!visited[i])) 
            {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

// Driver code
int main()
{
// number of vertices
int v = 5;

// adjacency matrix
adj= vector<vector<int>>(v,vector<int>(v,0));

//addEdge(0,1);
addEdge(0,2);
addEdge(1,3);
addEdge(1,4);
// perform bfs on the graph
bfs(0);
}
