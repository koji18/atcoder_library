#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    rep(i, n) {
        int target = a[i] - x;
        if(binary_search(a.begin(), a.end(), target)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
