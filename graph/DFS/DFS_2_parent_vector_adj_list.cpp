/*
DFS on tree without using Visited Array

-- we know that every node except root has only one parent
-- we can perform DFS from this property
-- in the adjancey list we can observe that for a node we have -> many childres & 1 parent only
-- as we know we have only 1 parent, we will maintain array of parents
-- instead of visited nodes
*/

// Algorithm is same as DFS_visiting just check for child!=parent instead of visit
// also when calling dfs interchange child and parent

#include<iostream>
#include<list>
#include<vector>

using namespace std;

void addEdge(int i,int j, vector<int> *graph)
{
	graph[i].push_back(j);
	// graph[j].push_back(i);
}

void dfs_new(int node,int parent, vector<int> *graph, vector<int> &parent_list)
{

	parent_list[node] = parent;
	// cout<<node<<",";

	for(auto child : graph[node])
	{
		// Need to iterate only on children
		if(child!=parent)
		{
			//jump to neigh , 
			// where current node is its parent
			dfs_new(child,node,graph,parent_list);
		}
	}
	// cout<<endl;
}


int main()
{
	int vertices = 11;
	vector<int> *graph  = new vector<int>[vertices];
	vector<int> parent_list(vertices,-1);

	addEdge(1,2,graph);
	addEdge(2,9,graph);
	addEdge(2,4,graph);
	addEdge(2,5,graph);
	addEdge(5,6,graph);
	addEdge(1,3,graph);
	addEdge(3,7,graph);
	addEdge(3,8,graph);
	addEdge(1,10,graph);
	// source, parent
    // 1, -1
	dfs_new(1, -1,graph, parent_list);

	for (int i=0; i<parent_list.size(); i++)
	{
		cout<< "Node-> "<<i<<" parent-> "<<parent_list[i]<<endl;
	}

	return 0;
}