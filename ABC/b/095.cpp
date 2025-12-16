#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    
    int smallest = 1e9, ans = 0;
    rep(i, n) {
        int m;
        cin >> m;
        smallest = min(smallest, m);
        x -= m;
        ans++;
    }
    cout << ans + (x/smallest) << endl;
}