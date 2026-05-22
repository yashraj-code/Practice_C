#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
vector<int> order;
int vis[N];

// mostly it is same only
// only differenece is pushback
void dfs(int cur, int par) 
{
	vis[cur] = 1;
	for (auto x : gr[cur]) 
	{
		if (!vis[x]) {
			dfs(x, cur);
		}
	}
	// I am here because I came back from the subtree
    // all the childs were inserted
    // at last we are inserting parents
    // parent will inserted at last
	order.push_back(cur);
	return;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) 
    {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y); // as it is directed
	}

	for (int i = 1; i <= n; i++) 
    {
		if (!vis[i]) dfs(i, 0);
	}
    // As parents were inserted last, 
    // now we reverse it such that parents are now at first
	reverse(order.begin(), order.end());

	for (auto x : order) 
        cout << x << " ";

	return 0;
}