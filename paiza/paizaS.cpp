#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> s(n, vector<char>(m));
    
    int sx, sy, gx, gy;
    rep(i, m) {
        rep(j, n) {
            cin >> s[j][i];
            if(s[i][j] == 's') {
                sx = i;
                sy = j;
                s[i][j] = '0';
            }
            else if(s[i][j] == 'g') {
                gx = i;
                gy = j;
                s[i][j] = '0';
            }
        }
    }
    vector<vector<int>> dist(m, vector<int>(n, 1e9));
    queue<pair<int, int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        rep(d, 4) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
            if (s[ny][nx] == '1') continue;
            if (dist[ny][nx] != 1e9) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    if (dist[gx][gy] == 1e9) {
        cout << "Fail" << endl;
    } else {
        cout << dist[gx][gy] << endl;
    }
}