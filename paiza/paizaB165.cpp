#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w, r, c, t;
    cin >> h >> w >> r >> c >> t;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> burned(h, vector<int>(w, -1)); 
    queue<pair<int, int>> q;

    if (s[r - 1][c - 1] == '#') {
        burned[r - 1][c - 1] = 0;
        q.push({r - 1, c - 1});
    }

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int step = 1; step <= t; step++) {
        int sz = q.size();
        rep(_, sz) {
            auto [x, y] = q.front(); q.pop();
            rep(dir, 4) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (s[nx][ny] == '#' && burned[nx][ny] == -1) {
                    burned[nx][ny] = step;
                    q.push({nx, ny});
                }
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            if (burned[i][j] == t) cout << 'B';
            else if (burned[i][j] != -1) cout << 'A'; 
            else cout << s[i][j];                     
        }
        cout << endl;
    }
}
