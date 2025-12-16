#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int f(int x) {
    return x*x + x * 2 + 3;
}
int main() {
   int t;
   cin >> t;
   cout << f(f(f(t)+t)+f(f(t))) << endl;
   return 0;
}
