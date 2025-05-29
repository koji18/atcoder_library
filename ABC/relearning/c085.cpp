#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, y;
    cin >> n >> y;
    int a = 0, b = 0; 
    rep(a, n+1) {
        rep(b, n+1) {
            int c = n - (a+b);
            if(0 <= c){
                if(a * 10000 + b * 5000 + c * 1000 == y) {
                    cout << a << " " << b << " " << c << '\n';
                    return 0;
            }
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << " " << '\n';
}
