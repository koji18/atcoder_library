#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;

    for(int bit = 0; bit < (1 << (4 - 1)); bit++) {
        string ans(1, s[0]);
        int sum = s[0] - '0';

        rep(i, 3) {
            int next = s[i+1] - '0';
            if(bit & (1 << i)) {
                ans += '+';
                sum += next;
            }
            else {
                ans += '-';
                sum -= next;
            }
            ans += s[i+1];
        }
        if(sum == 7) {
            cout << ans << "=7" << endl;
            return 0;
        }
    }
}