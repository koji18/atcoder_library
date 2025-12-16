#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    swap(s[a-1], s[b-1]);
    cout << s << endl;
}
