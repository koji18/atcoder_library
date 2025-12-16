#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, yuusya;
    cin >> n >> yuusya;
    for(int i = 0; i < n; i++) {
        int enemy;
        cin >> enemy;
        if(yuusya > enemy) {
            yuusya += enemy/2;
        }
        else if(yuusya < enemy) {
            yuusya /= 2;
        }
    }
    cout << yuusya << endl;
}
