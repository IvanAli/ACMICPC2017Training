#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

long long b, mod;
int n, q;
long long segtree[maxn << 2];

long long power(long long x, int e) {
	long long ret = 1;
	long long res = x;
	while (e) {
		if (e & 1) (ret *= res) %= mod;
		(res *= res) %= mod;
		e >>= 1;
	}
	return ret;
}

long long inv(long long x) {
	return power(x, mod - 2);
}

void update(int p, long long v, int id = 1, int l = 0, int r = n) {
	if (l + 1 == r) {
		segtree[id] = (power(b, p) * v) % mod;
		return;
	}
	int mid = l + r >> 1;
	if (p < mid) update(p, v, id << 1, l, mid);
	else update(p, v, id << 1 | 1, mid, r);
	segtree[id] = (segtree[id << 1] + segtree[id << 1 | 1]) % mod;
}

long long query(int x, int y, int id = 1, int l = 0, int r = n) {
	if (l >= x && r <= y) return segtree[id];
	if (l >= y || r <= x) return 0;
	int mid = l + r >> 1;
	return (query(x, y, id << 1, l, mid) + query(x, y, id << 1 | 1, mid, r)) % mod;	
}

int main() {
	while (scanf("%d%d%d%d", &b, &mod, &n, &q) && b + mod + n + q > 0) {
		memset(segtree, 0, sizeof segtree);
		while (q--) {
			char cmd[1];
			scanf("%s", cmd);
			if (cmd[0] == 'E') {
				int p, v; scanf("%d%d", &p, &v); p = n - p;
				update(p, v);
				
			} else if (cmd[0] == 'H') {
				int x, y, xq, yq; scanf("%d%d", &x, &y); xq = x, yq = y, x = n - yq, y = n - xq + 1;
				long long ans = query(x, y);
				(ans *= inv(power(b, x))) %= mod;
				printf("%lld\n", ans);
				
			} else assert(0);
		}
		printf("-\n");
	}
	return 0;
}