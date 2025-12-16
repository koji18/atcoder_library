#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    rep(i, n) cin >> v[i];

    int sum = 0;
    rep(i, n) {
        int c;
        cin >> c;
        if(v[i] > c) {
            sum += v[i] - c;
        }
    }
    cout << sum << endl;
}
