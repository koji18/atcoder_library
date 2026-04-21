#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(int v, vector<vector<int>> &a, vector<bool> &visited)
{
	visited[v] = true;
	for(int x : a[v])
	{
		if(visited[x] == false)
			dfs(x, a, visited);
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> a(n+1);

	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1].push_back(y-1);
	}
	vector<bool> visited(n, false);

	dfs(0, a, visited);

	cout << count(visited.begin(), visited.end(), true) << endl;
}
