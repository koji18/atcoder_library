#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s,t;
    cin >> s >> t;
    int check = 0;
    char tmp;
    for(int i = 0; i < (int)s.size()-1; i++) {
        if(s[i] != t[i]) {
            check++;
            tmp = s[i];
        }
        if(check == 1 && tmp != t[i]) {
            cout << "No" << endl;
            return 0;
        }
        if(check >= 3) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}