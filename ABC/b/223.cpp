#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    
    string maxS = s, minS = s;
    int n = s.size();
    rep(i, n) {
        string t = s.substr(i) + s.substr(0, i);
        if(t < minS) {
            minS = t;
        }
        if(t > maxS) {
            maxS = t;
        }
    }
    cout << minS << endl << maxS;
}
