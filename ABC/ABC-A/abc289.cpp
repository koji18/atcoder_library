#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    rep(i, s.size()){
        if(s[i] == '1') {
            cout << 0;
        }
        else {
            cout << 1;
        }
    }
}