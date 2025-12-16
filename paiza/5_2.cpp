#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    cin >> q;

    rep(i, q) {
        int k, left = 0, right = n;
        cin >> k;
        while(left < right){
            int mid = (left + right) / 2;
            if(a[mid] < k) {
                left = mid+1;
            } 
            else {
                right = mid;
            }
        }
        cout << n - right << endl;
    }
}