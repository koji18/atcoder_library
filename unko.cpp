#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    rep(i, 106) {
        if(i % 3 == a && i % 5 == b && i % 7 == c) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}