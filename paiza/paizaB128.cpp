#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<vector<char>>> m(n, vector<vector<char>>(3, vector<char> (3, '.')));
    rep(i, n) {
        int num = s[i] - '0';
        rep(j, 3) {
            rep(k, 3) {
                if(j * 3 + k < num) {
                    m[i][j][k] = '#';
                }
            }
        }
    }
    int cols = 3; 
    int rows = (n + cols - 1) / cols; 
    rep(row, rows) {
        rep(i, 3) { 
            rep(col, cols) {
                int index = row * cols + col;
                if (index >= n) continue; 
                rep(k, 3) {
                    cout << m[index][i][k];
                }
            }
            cout << endl;
        }
    }
}