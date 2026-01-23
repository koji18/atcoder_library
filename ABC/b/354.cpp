#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    int sum = 0;
    rep(i, n) {
        int c;
        cin >> s[i] >> c;
        sum += c; 
    }

    sort(s.begin(), s.end());
    cout << s[sum%n] << endl;
}
