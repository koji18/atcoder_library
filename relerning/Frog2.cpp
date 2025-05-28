#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n)cin >> h[i];

    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i-j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
        }
    } 
    cout << dp[n-1] << endl;
}