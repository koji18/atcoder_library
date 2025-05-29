#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 0; i < 101; i++) {
        rep(i, n) {
            if(a[i] % 2 == 1) {
                cout << ans << endl;
                return 0;
            }
            else {
                a[i] /= 2;
            }
        }
        ans++;
    }
    return 0;
}
