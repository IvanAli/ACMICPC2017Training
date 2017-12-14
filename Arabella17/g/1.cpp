#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 10005;

int T;
long long n, m, k;
long long x[N], y[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d%d", x + i, y + i);
		}
		long long ans = (n * (n + 1) / 2) * (m * (m + 1) / 2);
		for (int mask = 1; mask < 1 << k; mask++) {
			int popcnt = __builtin_popcount(mask);
			long long mul = 1;
			long long lef = N, rig = N, up = N, dow = N;
			for (int i = 0; i < 20; i++) if (mask & (1 << i)) {
				lef = min(lef, x[i]);
				rig = min(rig, n - x[i] + 1);
				up = min(up, y[i]);
				dow = min(dow, m - y[i] + 1);
			}
			mul = lef * rig * up * dow;
			if (popcnt & 1) ans -= mul;
			else ans += mul;
		}
		printf("%lld\n", ans);
	}
	return 0;
}