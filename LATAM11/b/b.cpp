#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n;
int b[maxn][maxn], sum[maxn][maxn];
int dp[maxn][maxn];

int main() {
	while (scanf("%d", &n) && n > 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) scanf("%d", &b[i][j]);
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n - i; j++) {
			sum[i][j] = b[i + j][i];
			if (j > 0) sum[i][j] += sum[i][j - 1];
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = -(1 << 30);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i; j++) {
				ans = max(ans, dp[i][j]);
				for (int k = 0; k <= min(j, n - i - 1); k++) dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + sum[i][j]);
			}
		}
		ans = max(ans, dp[n][0]);
		printf("%d\n", ans);
	}
	return 0;
}