#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;

    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(s[i] == 'L') {
                cout << "No" << endl;
                return 0;
            }
        }
        if(i % 2 == 1) {
            if(s[i] == 'R') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
