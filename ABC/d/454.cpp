#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string check_form(const string &s){
	string t;
	for(auto& c : s){
		t.push_back(c);
		if((int)t.size() >= 4 && t.substr(t.size() - 4, 4) == "(xx)") {
			t.erase(end(t) - 4, end(t));
			t += "xx";
		}
	}
	return t;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << (check_form(a) == check_form(b) ? "Yes" : "No") << '\n';
	}
}
