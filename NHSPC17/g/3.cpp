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

int query(int x, int y, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return 0;
	if (l >= x && r <= y) return segtree[id];
	int mid = l + r >> 1;
	return query(x, y, id << 1, l, mid) | query(x, y, id << 1 | 1, mid, r);
}

void print(int x) {
	string s;
	while (x) {
		if (x & 1) s.pb('1');
		else s.pb('0');
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	cerr << s << endl;
}
/*
int find(int x, int y, int msk, int id = 1, int l = 0, int r = n) {
	shift(id, l, r);
	if (l >= y || r <= x) return -1;
	int mid = l + r >> 1;
	if (l >= x && r <= y) {
		if (l + 1 == r) return l;
		int qq = query(x, y, id << 1, l, mid);
		if (qq & msk) return find(x, y, msk, id << 1, l, mid);
		return find(x, y, msk, id << 1 | 1, mid, r);
	}
	int ll = find(x, y, msk, id << 1, l, mid);
	int rr = find(x, y, msk, id << 1 | 1, mid, r);
	if (ll == -1) return rr;
	if (rr == -1) return ll;
	return min(ll, rr);
}
*/

int find(int x, int y, int msk, int id = 1, int l = 0, int r = n) {
    if(l+1==r) return l;
    int mid = (l+r)/2;
    if(x>=mid) return find(x, y, msk, id << 1 | 1, mid, r);
    else{
        int qq = query(x, y, id << 1, l, mid);
        if((qq & msk) && mid>x) return find(x, y, msk, id << 1, l, mid);
        else return find(x, y, msk, id << 1 | 1, mid, r);
    }
}

int get(int x, int y, int popcount, int id = 1, int l = 0, int r = n) {
	int msk = query(x, y);
	int best = 1 << 30;
	int ret = -1;
	for (int i = 0; i < 21; i++) {
		if (segtree[id] & (1 << i)) {
			if (abs(i - popcount) == abs(best - popcount)) {
				ret = min(ret, find(x, y, 1 << i));
			} else if (abs(i - popcount) < abs(best - popcount)) {
				best = i;
				ret = find(x, y, 1 << i);
			}
		}
	}
	return ret;
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
				int ans = get(l, r, __builtin_popcount(v));
				printf("%d\n", ans + 1);
			} else if (op == 2) {
				int l, r; scanf("%d%d", &l, &r); l--;
				update(l, r);
			} else assert(0);
		}
	}
	return 0;
}