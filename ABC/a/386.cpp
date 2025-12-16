#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> a(4);
    rep(i, 4)  {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int c = 0;
    if(a[0] != a[1]) c++;
    if(a[1] != a[2]) c++;
    if(a[2] != a[3]) c++;
    if(c == 1) {
        cout << "Yes" << endl;
    }
    else { 
        cout << "No" << endl;
    }
}