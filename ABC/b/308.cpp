#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m+1);
    vector<int> p(m+1);
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i+1];
    rep(i, m+1) cin >> p[i];
    int sum = 0;
    rep(i, n) {
        int price = p[0];
        for(int j = 1; j <= m; j++) {
            if(c[i] == d[j]) {
                price = p[j];
            }
        }
        sum += price;
    }
    cout << sum << endl;
}