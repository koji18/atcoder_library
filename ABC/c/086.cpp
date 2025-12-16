#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    bool check = true;
    int t = 0, x = 0, y = 0;
    rep(i, n) {
        int nt, nx, ny;
        cin >> nt >> nx >> ny;
        int dt = nt - t;
        int dist = abs(nx - x) + abs(ny - y);
        if(dist > dt || (dt - dist) % 2 != 0) {
            check = false;
        }
        t = nt;
        x = nx;
        y = ny;
    }
    cout << (check ? "Yes" : "No") << '\n';
}
