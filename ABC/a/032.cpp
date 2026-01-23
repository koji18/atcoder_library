#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    int ab = lcm(a, b);

    int ans = ((n + ab - 1) / ab) * ab;
    cout << ans << endl;
}
