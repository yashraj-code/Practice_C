#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
	//defining 2 variables 
	int V;
	list<int> *l;

public:
	Graph(int v)
	{
		V=v;
		l= new list<int>[V];
	}

	void addEdge(int i,int j,bool undir=true)
	{
		l[i].push_back(j);
		if(undir)
			{l[j].push_back(i);}
	}

    // give the source/root
	 vector<int> bfs(int source)
    {
		vector<int> bfs;
		queue<int> q;

        // maintain visited nodes
        // initialized with 0/false
        // bool visited[V] = {false}; is also same
		// bool *visited = new bool[V]{0};
		bool visited[V]={0};

		q.push(source);
		visited[source] = true;

		while(!q.empty())
        {
			//Do some work for every node
			int node = q.front();
			q.pop();
			bfs.push_back(node);

			//PUsh the nbrs of current node inside q if they are not already visited
			for(auto nbr : l[node])
            {
				if(!visited[nbr])
                    {q.push(nbr);   visited[nbr] = true;}
			}
		}
	return bfs;
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
	vector<int> ans = g.bfs(0);

	for(int i = 0; i < ans.size(); i++)
		{cout << ans[i] << " ";}

	return 0;
}








