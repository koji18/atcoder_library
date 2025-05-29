#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    int m = 1e5;
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
            m = min(m, a[i][j]);
        }
    }
    int sum = 0;
    rep(i, h) {
        rep(j, w) {
            sum += a[i][j] - m;
        }
    }
    cout << sum << endl;
    return 0;
}
