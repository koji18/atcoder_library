#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;

    int ans = -1;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'a') {
            ans = i+1;
        }
    }
    cout << ans << endl;
}
