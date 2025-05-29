#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<vector<int>> grid = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    int sum = 0;
    for(const auto& row : grid) {
        for(int x : row) {
            sum += x;
        }
    }
    cout << sum << endl;
    return 0;
}
