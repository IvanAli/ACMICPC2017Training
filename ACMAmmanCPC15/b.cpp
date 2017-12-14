#include <bits/stdc++.h>
using namespace std;

int T;
int n;
string s;
int memo[1005][2005][3];

int solve(int i, int p, int m) {
	if (m > 2) return 0;
	if (i == n) return p > 1000;
	if (memo[i][p][m] != -1) return memo[i][p][m];
	int ret = 0;
	if (m == 0) {
		if (s[i] == 'R') ret += solve(i + 1, p, m);
		if (s[i] == 'P') ret += solve(i + 1, p - 1, m);
		if (s[i] == 'S') ret += solve(i + 1, p + 1, m);
	} else if (m == 1) {
		if (s[i] == 'R') ret += solve(i + 1, p + 1, m);
		if (s[i] == 'P') ret += solve(i + 1, p, m);
		if (s[i] == 'S') ret += solve(i + 1, p - 1, m);
	} else if (m == 2) {
		if (s[i] == 'R') ret += solve(i + 1, p - 1, m);
		if (s[i] == 'P') ret += solve(i + 1, p + 1, m);
		if (s[i] == 'S') ret += solve(i + 1, p, m);
	}
	return memo[i][p][m] = ret + solve(i, p, m + 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		cin >> s;
		memset(memo, -1, sizeof memo);
		int ans = solve(0, 1000, 0);
		cout << ans << endl;
	}
	return 0;
}
