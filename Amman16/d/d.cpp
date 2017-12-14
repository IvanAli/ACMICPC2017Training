#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int T, n, m;
long long dp[maxn][maxn], hh[maxn], ww[maxn];
int grid[maxn][maxn];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &grid[i][j]);
		long long ans = 0;
		memset(dp, 0, sizeof dp);
		memset(hh, 0, sizeof hh);
		memset(ww, 0, sizeof ww);
		for (int i = 1; i <= n; i++) {
			int sz = 0;
			long long sum = 0;
			for (int j = 1; j <= m; j++) {
				int h = (grid[i][j] == grid[i - 1][j] ? dp[i - 1][j] + 1 : 1);
				dp[i][j] = h;
				int w = 1;
				if (grid[i][j] != grid[i][j - 1]) sz = 0, sum = 0;
				while (sz > 0 && h <= hh[sz - 1]) {
					sum -= hh[sz - 1] * ww[sz - 1];
					w += ww[sz - 1];
					sz--;
				}
				sum += w * h;
				ww[sz] = w;
				hh[sz] = h;
				sz++;
				ans += sum;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}