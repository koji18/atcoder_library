#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, t;
    cin >> n >> t;

    int cost = 1001;
    
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if(b > t) {
            continue;
        }
        else if(cost > a) {
            cost = a;
        }
    }
    if(cost > 1000) {
        cout << "TLE" << endl;
    }
    else {
        cout << cost << endl;
    }
}
