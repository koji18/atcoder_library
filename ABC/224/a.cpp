#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int n = s.size();
    if(s[n-1] == 'r' ) {
        cout << "er" << endl;
    }
    else {
        cout << "ist" << endl;
    }
}
