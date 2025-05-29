#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string a, b;
    cin >> a >> b;
    string c = a + b;
    int sum = stoi(c);
    int tmp = sqrt(sum);
    if(tmp * tmp == sum) {
        cout << "Yes" <<endl;
    }
    else {
        cout << "No" << endl;
    }
}
