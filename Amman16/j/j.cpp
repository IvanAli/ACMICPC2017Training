#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int T, n, q;
int b[maxn][1 << 9];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			int mask = 0;
			for (int j = 2; j <= 10; j++) {
				if (x % j == 0) mask |= 1 << (j - 2);
			}
			for (int j = 0; j < 1 << 9; j++) {
				if (j & mask) b[i][j] = 1;
				else b[i][j] = 0;
				if (i > 0) b[i][j] += b[i - 1][j];
			}
		}
		while (q--) {
			int l, r, s; scanf("%d%d%d", &l, &r, &s); l--, r--;
			int ans;
			if (s & 1) {
				ans = r - l + 1;
			} else {
				s >>= 1;
				ans = b[r][s];
				if (l > 0) ans -= b[l - 1][s];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}