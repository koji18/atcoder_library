#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x;
    cin >> x;
    
    int luck = (x / 500) * 1000 + (x % 500 / 5) * 5;

    cout << luck << endl;
}
