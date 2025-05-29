#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    if(42 <= n) {
        cout << "AGC0" << n+1 << endl;
    }
    else if(n <= 9){
        cout << "AGC00" << n << endl;
    }
    else {
        cout << "AGC0" << n << endl;
    }
    return 0;
}
