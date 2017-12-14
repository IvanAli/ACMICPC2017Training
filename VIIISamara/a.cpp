#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
const long long inf = 1e14;

int n, m;
long long dp[maxn][1005][3];
long long c[maxn], w[maxn], d[maxn];
int p[maxn];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i] >> w[i] >> d[i];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= 1000; j++) for (int k = 0; k <= 2; k++) dp[i][j][k] = -inf;
	for (int i = 0; i <= 2; i++) dp[0][200 + m][i] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j <= 1000; j++) for (int k = 0; k <= 2; k++) {
		dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
		if (j >= w[i + 1]) dp[i + 1][j - w[i + 1]][k] = max(dp[i + 1][j - w[i + 1]][k], dp[i][j][k] + c[i + 1]);
		if (k < 2 && j >= w[i + 1] - d[i + 1]) dp[i + 1][j - w[i + 1] + d[i + 1]][k + 1] = max(dp[i + 1][j - w[i + 1] + d[i + 1]][k + 1], dp[i][j][k] + c[i + 1]);
	}
	long long ans = 0;
	for (int i = 200; i <= 1000; i++) for (int j = 0; j <= 2; j++) ans = max(ans, dp[n][i][j]);
	cout << ans << endl;
	return 0;
}
