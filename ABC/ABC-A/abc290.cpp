#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n)cin >> a[i];

    int sum = 0;
    rep(i, m) {
        int m;
        cin >> m;
        sum += a[m-1];
    }
    cout << sum << endl;
}