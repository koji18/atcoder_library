#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n), c(n-1);
    int sum = 0;
    rep(i, n) cin >> a[i];
    rep(i, n) {
        int b;
        cin >> b;
        sum += b;
    }
    rep(i, n-1) cin >> c[i];

    for(int i = 0; i < n-1; i++) {
        if(a[i] == a[i+1]-1){
            sum += c[a[i]-1];
        }
    }
    cout << sum << endl;
}