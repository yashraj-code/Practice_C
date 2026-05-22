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
#include<queue>
using namespace std;


class Graph{

	int V;
	list<int> *l;

public:
	Graph(int v)
    {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=false)
    {
		l[i].push_back(j);
		if(undir)
            {l[j].push_back(i);}
	}


// if the destination is not given then it is considered -1
	void bfs(int source,int dest=-1)
    {
		queue<int> q;
		bool *visited = new bool[V]{0};
		int *dist = new int[V]{0};
		int *parent = new int[V];

        // int *parent = new int[V]{-1};
        // can also be done
		for(int i=0;i<V;i++)
            {parent[i] = -1;}

        // update the node info
        // same as before
		q.push(source);
		visited[source] = true;

		parent[source] = source;
		dist[source] = 0;

		while(!q.empty())
		{
			//Do same work for every node
			int f = q.front();
			//cout<<f <<endl;
			q.pop();

			//PUsh the nbrs of current node inside q if they are not already visited
			for(auto nbr : l[f]){
				if(!visited[nbr])
                {
					q.push(nbr);
                    // update parent and distance here
					//parent and dist

                    // parent node of neighbour is F
					parent[nbr] = f;

                    // dist(node) = dist(parent)+1
					dist[nbr] = dist[f] + 1;
					visited[nbr] = true;
				}
			}
		}

//print the shortest distance
		for(int i=0;i<V;i++){
			cout<<"Shortest dist to "<<i<<" is "<<dist[i] <<endl;
		}


//print the path from a source to any dest
		if(dest!=-1)
        {
			int temp = dest;
			while(temp!=source)
            {
				cout<<temp<<"-- ";

                // just to parent of destination value
				temp = parent[temp];
			}
			cout<<source<<endl;
		}

	}
	
	

};

int main(){
	Graph g(9);
	g.addEdge(0,3);
	g.addEdge(0,1);
	g.addEdge(3,4);
	g.addEdge(4,5);
	g.addEdge(2,6);
	g.addEdge(6,7);
	g.addEdge(5,6);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(7,8);
	g.addEdge(6,8);
	// g.addEdge();
	// g.addEdge(2,3);
	// g.addEdge(3,5);
	// g.addEdge(5,6);
	// g.addEdge(4,5);
	// g.addEdge(0,4);
	// g.addEdge(3,4);
	g.bfs(0,6);
	return 0;
}