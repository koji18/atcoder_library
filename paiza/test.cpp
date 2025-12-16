#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int input_rows, input_cols;
    cin >> input_rows >> input_cols;

    int h = input_cols;  
    int w = input_rows; 

    vector<vector<char>> grid(h, vector<char>(w));

    int sx = -1, sy = -1, gx = -1, gy = -1;

    rep(i, h) {
        rep(j, w) {
            string cell;
            cin >> cell;
            grid[i][j] = cell[0];

            if (grid[i][j] == 's') {
                sx = i;
                sy = j;
                grid[i][j] = '0';
            } else if (grid[i][j] == 'g') {
                gx = i;
                gy = j;
                grid[i][j] = '0';
            }
        }
    }

    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    queue<pair<int, int>> q;

    dist[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();

        rep(d, 4) {
            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (grid[ny][nx] == '1') continue;
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
