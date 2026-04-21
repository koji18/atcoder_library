#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<int>> graph;
vector<bool> visited;
vector<int> path;

bool dfs(int v, int y){
	visited[v] = true;
	path.push_back(v);

	if(v == y) return true;

	for(int next : graph[v]) {
		if(visited[next] == false)
			if(dfs(next, y)) return true;
	}

	path.pop_back();
	return false;
}

int main() {
	int n, x, y;
	cin >> n >> x >> y;

	graph.resize(n + 1);
	visited.resize(n + 1, false);

	rep(i, n - 1) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
	}
	dfs(x, y);

	rep(i, path.size()) {
		cout << path[i];

		if(i + 1 < (int)path.size()) {
			cout << ' ';
		}
	}
	cout << endl;

}
