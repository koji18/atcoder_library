#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }

    rep(i, n) {
        rep(j, n) {
            if(i == j) continue;
            bool kaibun = true;
            string tmp = s[i] + s[j];
            int a = tmp.size();
            for(int k = 0; k < a; k++) {
                if(tmp[k] != tmp[a-1-k]){
                    kaibun = false;
                    break;
                }
            }
            if(kaibun) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}