#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    char p, q;
    cin >> p >> q;
    vector<int> pos = {0, 3, 4, 8, 9, 14, 23};
    int ip = p - 'A';
    int iq = q - 'A';
    cout << abs(pos[ip] - pos[iq]) << endl;
}
