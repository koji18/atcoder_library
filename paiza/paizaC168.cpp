#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> total(n+1);
    int paiza;
    bool first = true;
    rep(i, n+1) {
        int m, d;
        cin >> m >> d;
        for(int j = 1; j < m; j++) {
            if(j == 4 || j == 6 || j == 9 || j == 11) {
                total[i] += 30;
            }
            else if(j == 2) {
                total[i] += 29;
            }
            else {
                total[i] += 31;
            }
        }
        total[i] += d;
        if(first) {
            paiza = total[i];
            first = false;
        }
    }
    sort(total.begin(), total.end());
    for(int i = 0;i < n+1; i++) {
        if(total[i] == paiza) {
            cout << i+1 << endl;
        }
    }
    rep(i, n+1) {
        if(total[i] <= 92) {
            if(total[i] == paiza) {
                paiza += 365;
            }
            total[i] += 365;
        }
    }
    sort(total.begin(), total.end());
    for(int i = 0;i < n+1; i++) {
        if(total[i] == paiza) {
            cout << i+1 << endl;
        }
    }
}
