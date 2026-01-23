#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];

    int sum = 0;
    rep(i, n) {
        int b;
        cin >> b;
        sum += a[i] * b;
    }
    if(sum == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
