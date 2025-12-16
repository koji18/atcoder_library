#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> l(n);
    rep(i, n) {
        int len;
        cin >> len;
        l[i].resize(len);
        for(int& x : l[i]) {
            cin >> x;
        }
    }
    int s, t;
    rep(i, q) {
        cin >> s >> t;
        cout << l[s-1][t-1] << endl;
    }
    return 0;
}
