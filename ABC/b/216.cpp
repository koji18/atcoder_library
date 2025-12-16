#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    double a, b, c, x;
    cin >> a >> b >> c >> x;
    if(a >= x) {
        cout << 1 << endl;
    }
    else if(b < x) {
        cout << 0 << endl;
    }
    else {
        cout << fixed << setprecision(15) << (c / (b - a)) << endl;
    }
}
