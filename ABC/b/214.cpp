#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int s, t;
    cin >> s >> t;

    int ans = 0;
    rep(a, 101) {
        rep(b, 101) {
            rep(c, 101) {
                if(a + b + c <= s && a * b * c <= t) ans++;
                
            }
        }
    }
    cout << ans << endl;
}
