#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int sum = 0;
    
    sum += (s[5] - '0');
    sum += (s[4] - '0') * 10;
    sum += (s[3] - '0') * 100;
    if(sum > 0 && sum < 350 && sum != 316) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}