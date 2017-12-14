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
int segtree[N << 2];
int lazy[N << 2];
int a[N];

void build(int id = 1, int l = 0, int r = n) {
	lazy[id] = 0;
	segtree[id] = 0;
	if (l + 1 == r) {
		int popcnt = __builtin_popcount(a[l]);
		segtree[id] = 1 << popcnt;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	segtree[id] = segtree[id << 1] | segtree[id << 1 | 1];
}

void shift(int id, int l, int r) {
	if (lazy[id]) {
		int msk = 0; for (int i = 0; i < 21; i++) if (segtree[id] & (1 << i)) {
			msk |= 1 << (20 - i);
		}
		segtree[id] = msk;
		if (l + 1 < r) lazy[id << 1] ^= 1, lazy[id << 1 | 1] ^= 1;
		lazy[id] = 0;
	}
}
/*
int find(int msk, int x, int y, int id = 1, int l = 0, int r = n) {
	int mid = l + r >> 1;
	if (l >= y || r <= x) return -1;
	if (l >= x && r <= y) {
		if (l + 1 == r) return l;
		if (segtree[id << 1] & msk) return find(msk, id << 1, l, mid);
		return find(msk, id << 1 | 1, mid, r);
	}
	int ll = find(msk, x, y, id << 1, l, mid);
	int rr = find(msk, x, y, id << 1 | 1, mid, r);
	if (ll == -1) return rr;
	if (rr == -1) return ll;
	if (ll < rr) return ll;
	return rr;
}
*/
int find(int msk, int id, int l, int r) {
	shift(id, l, r);
	if (l + 1 == r) return l;
	int mid = l + r >> 1;
	if (segtree[id << 1] & msk) return find(msk, id << 1, l, mid);
	else if (segtree[id << 1 | 1] & msk) return find(msk, id << 1 | 1, mid, r);
	else assert(0);
}

pair<int, int> query(int x, int y, int popcount, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return {10000, -1};
	if (l >= x && r <= y) {
		int ret = 1 << 30;
		for (int i = 0; i < 21; i++) {
			if (segtree[id] & (1 << i)) {
				if (abs(i - popcount) < abs(ret - popcount)) ret = i;
			}
		}
		return {ret, find(1 << ret, id, l, r)};
	}
	int mid = l + r >> 1;
	pair<int, int> ll = query(x, y, popcount, id << 1, l, mid);
	pair<int, int> rr = query(x, y, popcount, id << 1 | 1, mid, r);
	if (abs(ll.fst - popcount) <= abs(rr.fst - popcount)) return ll;
	return rr;
}

void update(int x, int y, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return;
	if (l >= x && r <= y) {
		int msk = 0; for (int i = 0; i < 21; i++) if (segtree[id] & (1 << i)) {
			msk |= 1 << (20 - i);
		}
		segtree[id] = msk;
		if (l + 1 < r) lazy[id << 1] ^= 1, lazy[id << 1 | 1] ^= 1;
		return;
	}
	int mid = l + r >> 1;
	update(x, y, id << 1, l, mid);
	update(x, y, id << 1 | 1, mid, r);
	segtree[id] = segtree[id << 1] | segtree[id << 1 | 1];
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d:\n", tc + 1);
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
//		memset(segtree, 0, sizeof segtree);
//		memset(lazy, 0, sizeof lazy);
		build();
		while (q--) {
			int op; scanf("%d", &op);
			if (op == 1) {
				int l, r, v; scanf("%d%d%d", &l, &r, &v); l--;
				int ans = query(l, r, __builtin_popcount(v)).snd;
//				int ans = find(1 << popcount, l, r);
				printf("%d\n", ans + 1);
			} else if (op == 2) {
				int l, r; scanf("%d%d", &l, &r); l--;
				update(l, r);
			} else assert(0);
		}
	}
	return 0;
}