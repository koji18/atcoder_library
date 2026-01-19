#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    string s[h];
    rep(i, h) cin >> s[i];

    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
