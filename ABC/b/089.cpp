#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    rep(i, n) {
        char tmp;
        cin >> tmp;
        if(tmp == 'Y') {
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
}
