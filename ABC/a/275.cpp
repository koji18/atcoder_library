#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    int t = -1;
    int ans = 0;
    rep(i, n) {
        int b;
        cin >> b;
        if(b > t) {
            t = b;
            ans = i+1;
        }
    }
    cout << ans << endl;
}
