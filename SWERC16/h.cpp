#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef unsigned long long uint64;

int d, h;
map<vector<int>, uint64> memo;
vector<vector<int> > perm;
set<uint64> ans;

void solve(vector<int> v) {
	uint64 ret = 0;
	sort(v.begin(), v.end());
	if (memo.count(v)) return;
	for (int i = 0; i < v.size(); i++) {
		v[i]--;
		if (v[i] >= 0) {
			solve(v);
			vector<int> vv = v;
			sort(vv.begin(), vv.end());
			ret += memo[vv];
		}
		v[i]++;
	}
	memo[v] = ret;
}

void gen(int i, int cur, int sum, vector<int> v) {
	if (i == d) {
		if (sum == h - 1) perm.pb(v);
		return;
	}
	for (int j = cur; j < h; j++) {
		if (sum + j > h - 1) continue;
		v.pb(j);
		gen(i + 1, j, sum + j, v);
		v.pop_back();
	}
}

int main() {
	cin >> d >> h;
	vector<int> b(d, 0);
	memo[b] = 1;
	gen(0, 0, 0, vector<int>());
	for (auto i : perm) {
		solve(i);
		ans.insert(memo[i]);
	}
	for (auto i : ans) cout << i << endl;
	return 0;
}
