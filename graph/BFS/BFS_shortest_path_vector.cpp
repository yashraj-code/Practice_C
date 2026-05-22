/*
we keep storing the parent of a given vertex while doing the breadth-first search.
 We first initialize an array dist[0, 1, …., v-1] such that dist[i] stores 
 the distance of vertex i from the source vertex and 
 array par[0, 1, ….., v-1] such that par[i] represents the parent 
 of the vertex i in the breadth-first search starting from the source. 

Now we get the length of the path from source to any other vertex from array dist[], 
and for printing the path from source to any vertex we can use array par[].
*/

#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> *graph, int i,int j)
{
	graph[i].push_back(j);
	graph[j].push_back(i);
}

// if the destination is not given then it is considered -1
void bfs(vector<int> *graph, int vertices, int source,int dest=-1)
{
	// parent array
	vector<int> parent(vertices,-1);
	//queue
	queue<int> que;
	//dist array
	vector<int> dist(vertices,-1);
	//visited array
	vector<bool> visited(vertices,false);


	// as before
	que.push(source);
	visited[source]=true;

	parent[source]=source;
	dist[source]=0;

	while(!que.empty())
	{
		// same thing as done in bs
		int f=que.front();
		que.pop();

		//go for neighbours
		for(auto neig:graph[f])
		{
			if(visited[neig]==false)
			{
				que.push(neig);
				visited[neig]=true;

				//update distance and parent
				//parent of neig is f (original node)
				parent[neig]=f;
				dist[neig]=dist[f]+1;
			}
		}
	}

	//print the shortest distance
	for(int i=0;i<vertices;i++)
		{
			cout<<"Shortest dist to "<<i<<" is "<<dist[i] <<endl;
		}


	//print the path from a source to any dest
	int temp = dest;
	while (temp!=source)
	{
		cout<<temp<<"--";
		temp = parent[temp];
	}
	cout<<source<<endl;
}



int main()
{
	int vertices = 7;
	
	// Graph
	vector<int> *graph = new vector<int> [vertices];

	addEdge(graph,0,1);
	addEdge(graph,1,2);
	addEdge(graph,2,3);
	addEdge(graph,3,5);
	addEdge(graph,5,6);
	addEdge(graph,4,5);
	addEdge(graph,0,4);
	addEdge(graph,3,4);
	bfs(graph,vertices,1,6);
	return 0;
}