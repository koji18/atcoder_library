#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    char c, ca;
    string s;
    cin >> n >> c >> ca >> s;
    rep(i, n) {
        if(s[i] != c) {
            s[i] = ca;
        }
    }
    cout << s << endl;
}