#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> s(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    vector<vector<int>> dp(h, vector<int>(w, 0));
    rep(j, w) dp[0][j] = s[0][j];

    for (int i = 1; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int dj = -1; dj <= 1; dj++) {
                int prev_col = j + dj;
                if (0 <= prev_col && prev_col < w) {
                    dp[i][j] = max(dp[i][j], dp[i-1][prev_col] + s[i][j]);
                }
            }
        }
    }

    int ans = *max_element(dp[h-1].begin(), dp[h-1].end());
    cout << ans << endl;
}
