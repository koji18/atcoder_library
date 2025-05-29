#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long ans = 0;
    for(int bit = 0; bit < (1 << (n - 1)); bit++) {
        long long sum = 0;
        long long q = s[0] - '0';
        rep(i, n-1) {
            if(bit & (1 << i)) {
                sum += q;
                q = s[i+1] - '0';
            }
            else {
                q = q * 10 + (s[i+1] - '0');
            }
        }
        sum += q;
        ans += sum;
    }
    cout << ans << endl;
}
