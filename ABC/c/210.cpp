#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> c(n);
	rep(i, n)
		cin >> c[i];
	
	unordered_map<int, int> cnt;
	int kind = 0;
	
	rep(i, k)
	{
		if(cnt[c[i]] == 0)
			kind++;
		cnt[c[i]]++;
	}

	int ans = kind;

	for(int left = 0; left < n - k; left++)
	{
		int out = c[left];
		int in = c[left + k];

		cnt[out]--;
		if (cnt[out] == 0)
			kind--;
		if (cnt[in] == 0)
			kind++;
		cnt[in]++;

		ans = max(ans, kind);
	}

	cout << ans << endl;
	return 0;
}
