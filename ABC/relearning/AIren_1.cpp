#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> a = {10, 20, 30,40};
    int sum = 0;
    for(int x : a){
        sum += x;
    }
    cout << sum << endl;
    return 0;
}
 