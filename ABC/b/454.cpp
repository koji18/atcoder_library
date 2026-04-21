#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> f(n);
	rep(i, n) cin >> f[i];
	sort(f.begin(), f.end());

	bool daburi = false;
	for(int i = 1; i < n; i++)
	{
		if(f[i-1] == f[i])
			daburi = true;
	}
	if(daburi)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;

	for(int i = 1; i <= m; i++)
	{
		bool aru = false;
		for(int j = 0; j < n; j++)
		{
			if(f[j] == i)
				aru = true;
		}
		if(!aru)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
