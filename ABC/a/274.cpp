#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    cin >> a >> b;

    double ans = (double)b / a;
    ans = round(ans * 1000.0L) / 1000.0L;
    cout << fixed << setprecision(3) << (double)ans << endl;
}
