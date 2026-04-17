#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;

    cin >> a >> b;
    for(int i = 1; i <= 1000; i++)
    {
        if((floor(i * 0.08) == a) && floor(i * 0.1) == b)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
