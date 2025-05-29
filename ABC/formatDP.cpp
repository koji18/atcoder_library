#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9; // 十分大きい値（必要に応じて）

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, INF); // dp[i]: i 番目の状態の最小コストなど
    dp[0] = 0; // 初期条件（問題に応じて変える）

    for (int i = 1; i <= N; ++i) {
        // 遷移（例：1つ前と2つ前からの移動）
        if (i - 1 >= 0) dp[i] = min(dp[i], dp[i - 1] + cost(i - 1, i));
        if (i - 2 >= 0) dp[i] = min(dp[i], dp[i - 2] + cost(i - 2, i));
    }

    cout << dp[N] << endl; // 答えを出力（問題に応じて）
}
