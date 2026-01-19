#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    unsigned long long ans = 0;
    rep(i, 64) {
        int a;
        cin >> a;
        if(a) {
            ans |= (1ULL << i);
        }
    }
    cout << ans << endl;
    return 0;
}
