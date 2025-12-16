#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s, t;
    cin >> s >> t;

    if(s == t) {
        cout << "Yes" << endl;
        return 0;
    }

    int n = s.size();
    for(int i = 0; i < n-1; i++) {
        string a = s;
        char tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
        if(a == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}