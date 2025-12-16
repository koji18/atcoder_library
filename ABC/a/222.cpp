#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string str;
    cin >> str;
    while(str.size() < 4){
        str.insert(str.begin(), '0');
    }
    cout << str << endl;
}
