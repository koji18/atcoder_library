#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
     long long ans = 1;
     for(long long i = 0; i < 63; i++) {
        if(ans > n) {
            cout << i-1 << endl;
            break;
        }
        ans *= 2;
     }
     return 0;
}