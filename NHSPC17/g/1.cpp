#include <bits/stdc++.h>
#define fst first
#define index inddd
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 1000005;

int T;
int n, q;
int segtree[N << 2][21];
int lazy[N << 2];
int a[N];

void build(int id = 1, int l = 0, int r = n) {
	lazy[id] = 0;
	for (int i = 0; i < 21; i++) segtree[id][i] = 1 << 30;
	if (l + 1 == r) {
		int popcnt = __builtin_popcount(a[l]);
		for (int i = 0; i < 21; i++) segtree[id][i] = 1 << 30;
		segtree[id][popcnt] = l;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	for (int i = 0; i < 21; i++) segtree[id][i] = min(segtree[id << 1][i], segtree[id << 1 | 1][id]);
}

void shift(int id, int l, int r) {
	if (lazy[id]) {
		for (int i = 0; i < 21; i++) swap(segtree[id][i], segtree[id][20 - i]);
		if (l + 1 < r) lazy[id << 1] ^= 1, lazy[id << 1 | 1] ^= 1;
		lazy[id] = 0;
	}
}

int query(int x, int y, int popcount, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return 1 << 30;
	if (l >= x && r <= y) {
		int ret = 1 << 30;
		int best = 1 << 30;
		for (int i = 0; i < 21; i++) {
			if (segtree[id][i] < 1 << 30 && abs(i - popcount) <= best) {
				best = abs(i - popcount);
				ret = min(ret, segtree[id][i]);
			}
		}
		return ret;
	}
	int mid = l + r >> 1;
	int ll = query(x, y, popcount, id << 1, l, mid);
	int rr = query(x, y, popcount, id << 1 | 1, mid, r);
	assert(min(ll, rr) < 1 << 30);
	return min(ll, rr);
}

void update(int x, int y, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return;
	if (l >= x && r <= y) {
		for (int i = 0; i < 21; i++) swap(segtree[id][i], segtree[id][20 - i]);
		if (l + 1 < r) {
			lazy[id << 1] ^= 1;
			lazy[id << 1 | 1] ^= 1;
		}
		return;
	}
	int mid = l + r >> 1;
	update(x, y, id << 1, l, mid);
	update(x, y, id << 1 | 1, mid, r);
	for (int i = 0; i < 21; i++) segtree[id][i] = min(segtree[id << 1][i], segtree[id << 1 | 1][i]);
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d:\n", tc + 1);
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
//		memset(segtree, 0, sizeof segtree);
		build();
		while (q--) {
			int op; scanf("%d", &op);
			if (op == 1) {
				int l, r, v; scanf("%d%d%d", &l, &r, &v); l--;
				int ans = query(l, r, __builtin_popcount(v));
				printf("%d\n", ans + 1);
			} else if (op == 2) {
				int l, r; scanf("%d%d", &l, &r); l--;
				update(l, r);
			} else assert(0);
		}
	}
	return 0;
}