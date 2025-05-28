#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int count = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if(s == "For") {
            count++;
        }
    }
    int ni = n/=2;
    if(count > ni) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;

    }
    return 0;
}