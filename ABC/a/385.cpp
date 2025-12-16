#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && a == c) {
        cout << "Yes" << endl;
    }
    else if(a + b == c || b + c == a || a + c == b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}