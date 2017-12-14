#include <bits/stdc++.h>
using namespace std;

const int maxw = 15505;
const int maxn = 155;
const int mod = 1e9 + 7;

int T, n, m, k, w;
long long dp1[maxw], dp2[maxw];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &n, &m, &k, &w);
		for (int i = 0; i < maxw; i++) dp1[i] = dp2[i] = 0;
		dp1[0] = dp2[0] = 1;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			for (int j = w; j >= x; j--) (dp1[j] += dp1[j - x]) %= mod;
		}
		for (int i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			for (int j = w; j >= x; j--) (dp2[j] += dp2[j - x]) %= mod;
		}
		long long ans = 0;
		for (int i = 0; i <= w; i++) {
			int j = w - i;
			if (abs(i - j) <= k) (ans += ((dp1[i] * dp2[j]) % mod)) %= mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
