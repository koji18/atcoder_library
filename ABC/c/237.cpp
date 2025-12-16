#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;

    int left = 0, right = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(s[i] == 'a') {
            left++;
        }
        else {
            break;
        }
    }
    for(int i = (int)s.size() - 1; i >= 0; i--) {
        if(s[i] == 'a') {
            right++;
        }
        else {
            break;
        }
    }
    if(left > right) {
        cout << "No" << endl;
    }
    else {
        string tmpS = string(right-left, 'a') + s;

        string reverseS = tmpS;
        reverse(reverseS.begin(), reverseS.end());

        if(tmpS == reverseS) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
