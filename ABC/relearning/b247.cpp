#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i] >> t[i];

    rep(i, n) {
        bool s_used = false, t_used = false;
        rep(j, n) {
            if (i == j) continue;
            if (s[i] == s[j] || s[i] == t[j]) s_used = true;
            if (t[i] == s[j] || t[i] == t[j]) t_used = true;
        }
        
        if (s_used && t_used) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}