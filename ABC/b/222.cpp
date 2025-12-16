#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, p;
    cin >> n >> p;

    int cnt = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if(p > a) cnt++;
    }
    cout << cnt << endl;
}