#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    bool checked[n][m]={};
    rep(i, n) {
        cin >> p[i];
        int c;
        cin >> c;
        rep(j, c) {
            int f;
            cin >> f;
            f--;
            checked[i][f] = true;
        }
    }
    bool ans = false;
    rep(i, n) {
        rep(j, n) {
            bool p1 = false;
            bool p2 = true;
            bool p3 = false;

            if(p[i] >= p[j]) p1 = true;
            rep(k, m) {
                if(checked[i][k] && !checked[j][k]) p2 = false;
            }
            if(p[i] > p[j]) p3 = true;
            rep(k, m) {
                if(checked[j][k] && !checked[i][k]) p3 = true;
            }
            if(p1 && p2 && p3) ans = true;
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
 }