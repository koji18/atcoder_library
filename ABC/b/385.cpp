#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    string t;
    cin >> t;

    int cnt = 0;
    for(int i = 0; i < (int)t.size(); i++) {
        if(t[i] == 'U' && s[x-1][y] != '#') {
            x--;
            if(s[x][y] == '@') {
                cnt++;
                s[x][y] = '.';
            }
        }
        if(t[i] == 'D' && s[x+1][y] != '#') {
            x++;
            if(s[x][y] == '@') {
                cnt++;
                s[x][y] = '.';
            }
        }
        if(t[i] == 'L' && s[x][y-1] != '#') {
            y--;
            if(s[x][y] == '@') {
                cnt++;
                s[x][y] = '.';
            }
        }
        if(t[i] == 'R' && s[x][y+1] != '#') {
            y++;
            if(s[x][y] == '@') {
                cnt++;
                s[x][y] = '.';
            }
        }
    }
    x++; y++;
    cout << x << " " << y << " " << cnt << endl;
}
