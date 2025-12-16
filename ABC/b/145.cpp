#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> b(n, vector<int>(n));
    rep(i,n)rep(j,n)cin >> b[i][j];
    rep(l, k) {
        int c;
        cin >> c;
        rep(i, n) {
            rep(j, n) {
                if(b[i][j] == c) {
                    b[i][j] = 0;
                }
            }
        }
    }
    int cnt = 0;
    rep(i, n) {
        bool row = true;
        rep(j, n) {
            if(b[i][j] != 0) {
                row = false;
                break;
            }
        }
        if(row) {
            cnt++;
        }
    }
    rep(i, n) {
        bool columns = true;
        rep(j, n) {
            if(b[j][i] != 0) {
                columns = false;
                break;
            }
        }
        if(columns) {
            cnt++;
        }
    }
    bool diag1 = true;
    rep(i, n) {
        if(b[i][i] != 0) {
            diag1 = false;
            break;
        }
    }
    if(diag1) cnt++;

    bool diag2 = true;
    rep(i, n) {
        if(b[i][n - 1 - i] != 0) {
            diag2 = false;
            break;
        }
    }
    if(diag2) cnt++;
    cout << cnt << endl;
}