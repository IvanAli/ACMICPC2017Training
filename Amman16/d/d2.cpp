#include <bits/stdc++.h>
using namespace std;


int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &grid[i][j]);
		for (int j = 0; j < m; j++) for (int i = n - 1; i >= 0; i--) {
			if (i < n - 1 && grid[i + 1][j] == grid[i][j]) help[i][j] = help[i + 1][j] + 1;
			else help[i][j] = 1;
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long vlen = 1 << 30;
			long long hlen = 0;
			for (int j = 0; j < m; j++) {
				while (help[i][j] < stk[sz - 1]) tot -= stk[sz], sz--;
				if (j > 0 && grid[i][j] > grid[i][j - 1]) stk[sz] = grid[i][j] - grid[i][j - 1], tot += grid[i][j] - grid[i][j - 1], sz++; 
				if (j > 0 && grid[i][j - 1] != grid[i][j]) hlen = 0, vlen = 1 << 30;
				vlen = min(vlen, help[i][j]);
				hlen++;
				ans += hlen * vlen + tot;
			}	
		}
		printf("%lld\n", ans);
	}
	return 0;
}