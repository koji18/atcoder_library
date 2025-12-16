#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    rep(i, n) {
        cin >> w[i];
        sum += w[i];
    }
    int tmp = sum;
    sum = sum/2;

    int s1 = 0, s2 = 0, ans = 1e9;
    rep(i, n) {
        s1 += w[i];
        s2 = tmp - s1;
        ans = min(ans, abs(s1-s2));
    }
    cout << ans << endl;
}
