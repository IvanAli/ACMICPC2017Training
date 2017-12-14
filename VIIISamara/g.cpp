#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	stack<int> s;
	vector<pair<int, int>> ans;
	for (int i = 0; i < 2*n; i++) {
		string d; int v; cin >> d >> v;
		if (d[0] == 'i') {
			if (!s.empty()) {
				ans.pb({s.top(), v});
			}
			s.push(v);
		}
		else {
			s.pop();
		}
	}
	for (auto it : ans) cout << it.first << " " << it.second << endl;
	return 0;
}
