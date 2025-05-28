#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(3, 0));
    rep(i, n) {
        rep(j, 3){
            cin >> m[i][j];
        }
    }
    
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0] = m[0];
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(j != k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + m[i][j]);
                }
            }
        }
    }
    int ans = *max_element(dp[n-1].begin(), dp[n-1].end());
    cout << ans << endl;
}