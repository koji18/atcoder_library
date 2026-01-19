#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, k) {
        a.erase(a.begin());
        a.push_back(0);
    }
    rep(i, n) {
        cout << a[i] << " ";
    }
}
