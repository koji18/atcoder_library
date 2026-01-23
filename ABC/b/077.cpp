#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    
    int ans = (int)floor(sqrt(n));
    ans *= ans;
    cout << ans << endl;
}
