#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;

    int cnt = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == '0' && s[i+1] == '0') {
            i++;
        }
        cnt++;
    }
    cout << cnt << endl;
}
