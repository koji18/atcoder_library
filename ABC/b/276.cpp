#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n+1);

	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1].push_back(y);
		a[y - 1].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		sort(a[i].begin(), a[i].end());
		cout << size(a[i]);
		for(int a : a[i])
			cout << ' ' << a;
		cout << endl;
	}
}
