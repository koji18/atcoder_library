#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> xs, ys;

    // 上
    for (int j = 0; j < n; j++) { xs.push_back(0); ys.push_back(j); }
    // 右
    for (int i = 1; i < n; i++) { xs.push_back(i); ys.push_back(n-1); }
    // 下
    for (int j = n-2; j >= 0; j--) { xs.push_back(n-1); ys.push_back(j); }
    // 左
    for (int i = n-2; i >= 1; i--) { xs.push_back(i); ys.push_back(0); }

    vector<char> ring;
    for (int k = 0; k < (int)xs.size(); k++) ring.push_back(a[xs[k]][ys[k]]);

    rotate(ring.rbegin(), ring.rbegin() + 1, ring.rend());

    for (int k = 0; k < (int)xs.size(); k++) a[xs[k]][ys[k]] = ring[k];

    rep(i, n) cout << a[i] << endl;
}