#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i < (int)(n); i++)

int main() {
    int m, n;
    cin >> m >> n;
    int x = 2;
    rep(i, m) {
        cout << i << " + " << x << " = " << endl;
        x++;
    }
    rep(i, n) {
        cout << i << " - " << x << " = " << endl;
    }
}