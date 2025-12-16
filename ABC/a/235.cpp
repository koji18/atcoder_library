#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    int sum = 0;
    sum += a - '0';
    sum += b - '0';
    sum += c - '0';
    cout << sum*111 << endl;
}
