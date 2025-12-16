#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> yasai(n, vector<int>(k));
    vector<int> cheap(k, 1e9);
    rep(i,n) {
        rep(j,k) {
            cin >> yasai[i][j];
            cheap[j] = min(cheap[j], yasai[i][j]);
        }
    }
    int cnt = 0;
    rep(i,n) {
        rep(j, k) {
            if(yasai[i][j] == cheap[j]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}