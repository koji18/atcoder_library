#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;

    vector<bool> saikyo(n, true);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        saikyo[b-1] = false;
    }

    int ans = -1;
    rep(i, n) {
        if((ans == -1) && (saikyo[i])) {
            ans = i+1;
        }
        else if((ans != -1) && (saikyo[i])) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
