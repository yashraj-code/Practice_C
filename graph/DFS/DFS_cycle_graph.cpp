/*
objective - detect a cyle in undirected graph
we will use concept of parent that we leanerd in DFS_2
Have adjanecy list in mind
1  ->2->3->4->5

A black Edge cannot be between a parent and a child
in an undirected graph
to detect cycle we need to see if the child is trying to jump to visited child again
*/

#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

//list of vectors
vector<int> gr[N];
bool vis[N];
bool cycle = false;

void dfs(int cur, int par) 
{
	//visited
	vis[cur] = true;
	for (auto x : gr[cur]) 
	{
		if (!vis[x]) 
		{
			// visit x where
			// cur is parent of x
			dfs(x, cur);
		}
		// checking for cycle here
		// if the node is visited and is not equal to parent
		else if (x != par) 
		{
			// cout<< cur <<" "<< x << '\n';
			cycle = true;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);

	}

	// so that no vertices miss , if there is a break
	// same as Connected Components in an Undirected Graph
	for (int i = 1; i <= n; i++) 
	{
		if (!vis[i]) {
			dfs(i, 0);
		}
	}

	if (cycle) {
		cout << "Yes cycle found";
	}
	else {
		cout << "Not found";
	}


	return 0;
}