#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(p <= i && i <= q)cout << a[i+r-p];
        else if(r <= i && i <= s) cout << a[i+p-r];
        else cout << a[i];
        
        cout << " ";
    }
}