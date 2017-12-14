#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const long long inf = 1e14;

int n, m;
long long memo[maxn][805];
long long c[maxn], w[maxn], d[maxn];
int p[maxn];

long long solve(int x, int y, int i, int ww) {
	if (ww < 0) return -inf;
	// if (r < 0) return -inf;
	if (i == n) return 0;
	if (memo[i][ww] != -1) return memo[i][ww];
	long long ret = -inf;
	if (i == x || i == y) {
		ret = max(ret, c[i] + solve(x, y, i + 1, ww - w[i]));
	} else {
		ret = max(ret, solve(x, y, i + 1, ww));
		ret = max(ret, c[i] + solve(x, y, i + 1, ww - w[i]));
	}
	return memo[i][ww] = ret;
}

long long dp[maxn][805][3];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> c[i] >> w[i] >> d[i];
	long long ans = 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		memset(memo, -1, sizeof memo);
		ans = max(ans, solve(i, j, 0, m + d[i] + d[j]));
		if (ans == 142) fprintf(stderr, "selected: %d %d\n", i, j);
	}
	for (int i = 0; i < n; i++) {
		memset(memo, -1, sizeof memo);
		ans = max(ans, solve(i, -1, 0, m + d[i]));
	}
	cout << ans << endl;
	return 0;
}
