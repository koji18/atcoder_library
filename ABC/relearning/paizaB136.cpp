#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, h, w;
    cin >> n >> h >> w;
    int ny, nx;
    string s;
    cin >> ny >> nx >> s;
    
    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j];
        }
    }
    nx--, ny--;
    rep(i, n) {
        if(s[i] == 'F')ny--;
        if(s[i] == 'B')ny++;
        if(s[i] == 'R')nx++;
        if(s[i] == 'L')nx--;
        cout << c[ny][nx] << endl;
    }
}
