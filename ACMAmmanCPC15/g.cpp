#include <bits/stdc++.h>
using namespace std;

int T;
int n, s;
int memo[15][1150];
int a[15];

int solve(int i = 0, int w = s + 100) {
	if (i == n) {
		if (w > 100) return -10000000;
		return 0;
	}
	if (w <= 100) return 0;
	if (memo[i][w] != -1) return memo[i][w];
	int ret = max(1 + solve(i + 1, w - a[i]), solve(i + 1, w));
	return memo[i][w] = ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> s;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		memset(memo, -1, sizeof memo);
		int ans = solve();
		cout << ans << endl;
	}
	return 0;
}
