#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int l, h, n;
    cin >> l >> h >> n;
    
    rep(i, n) {
        int a;
        cin >> a;
        if(a < l) {
            cout << l - a << endl;
        }
        else if(a > h) {
            cout << -1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
