#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int T;
string s1, s2;
set<string> st;

void solve(int i, int j, string& cur) {
	if (i == s1.size() && j == s2.size()) {
		st.insert(cur);
		return;
	}
	if (i == s1.size()) {
		cur.pb(s2[j]);
		solve(i, j + 1, cur);
		cur.pop_back();
	} else if (j == s2.size()) {
		cur.pb(s1[i]);
		solve(i + 1, j, cur);
		cur.pop_back();
	} else {
		cur.pb(s1[i]);
		solve(i + 1, j, cur);
		cur.pop_back();
		cur.pb(s2[j]);
		solve(i, j + 1, cur);
		cur.pop_back();
	}
}

int main() {
	cin >> T;
	while (T--) {
		st.clear();
		cin >> s1 >> s2;
		string cur = "";
		solve(0, 0, cur);
		for (auto it = st.begin(); it != st.end(); it++) cout << *it << endl;
		cout << endl;
	}
	return 0;
}