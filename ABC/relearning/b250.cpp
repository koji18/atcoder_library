#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<string> s(a*n, "");

    rep(i, n) {
        rep(i1, a) {
            rep(j, n) {
                char c = ((i+j) % 2 == 0) ? '.' : '#';
                rep(j1, b) {
                    s[i * a + i1] += c;
                }
            }
        }
    }
    for(const string& row : s) {
        cout <<row << '\n';
    }

    return 0;
}
