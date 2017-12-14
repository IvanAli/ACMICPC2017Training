#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 1000005;
const int MX = 0;
const int MN = 1;

int T;
int n, q;
int segtree[N << 4][2];
int a[N << 1];
int timer;
int tin[N << 2], tout[N << 2];
int where[N << 2];
int lazy[N << 4];
vector<int> graph[N << 1];

void dfs(int v) {
	tin[v] = timer;
	where[timer] = v;
	timer++;
	for (auto to : graph[v]) {
		dfs(to);
	}
	tout[v] = timer;
	where[timer] = v;
	timer++;
}

void build(int id = 1, int l = 0, int r = timer) {
	lazy[id] = 0;
	if (l + 1 == r) {
		segtree[id][MX] = segtree[id][MN] = a[where[l]];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid, r);
	segtree[id][MX] = max(segtree[id << 1][MX], segtree[id << 1 | 1][MX]);
	segtree[id][MN] = min(segtree[id << 1][MN], segtree[id << 1 | 1][MN]);
}

void shift(int id, int l, int r) {
	if (lazy[id]) {
		segtree[id][MX] += lazy[id];
		segtree[id][MN] += lazy[id];
		if (l + 1 < r) {
			lazy[id << 1] = lazy[id << 1 | 1] = lazy[id];
		}
		lazy[id] = 0;
	}
}

int query(int x, int y, int which, int id = 1, int l = 0, int r = timer) {
	shift(id, l, r);
	if (l >= y || r <= x) {
		if (which == MX) return -1;
		if (which == MN) return 1 << 30;
	}
	if (l >= x && r <= y) return segtree[id][which];
	int mid = l + r >> 1;
	int ql = query(x, y, which, id << 1, l, mid);
	int qr = query(x, y, which, id << 1 | 1, mid, r);
	if (which == MX) return max(ql, qr);
	if (which == MN) return min(ql, qr);
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = timer) {
	shift(id, l, r);
	if (l >= y || r <= x) return;
	if (l >= x && r <= y) {
		segtree[id][MX] += val;
		segtree[id][MN] += val; 
		if (l + 1 < r) {
			lazy[id << 1] += val;
			lazy[id << 1 | 1] += val;
		}
		return;
	}
	int mid = l + r >> 1;
	update(x, y, val, id << 1, l, mid);
	update(x, y, val, id << 1 | 1, mid, r);
	segtree[id][MX] = max(segtree[id << 1][MX], segtree[id << 1 | 1][MX]);
	segtree[id][MN] = min(segtree[id << 1][MN], segtree[id << 1 | 1][MN]);
}

int calc(int v, int which) {
	int ret = a[v];
	for (auto to : graph[v]) {
		if (which == MN) ret = min(ret, calc(to, which));
		if (which == MX) ret = max(ret, calc(to, which));
	}
	return ret;
}

void upd(int v, int val) {
	a[v] += val;
	for (auto to : graph[v]) upd(to, val);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) graph[i].clear();
		timer = 0;
		for (int i = 0; i + 1 < n; i++) {
			int foo; scanf("%d", &foo);
			foo--;
			graph[foo].pb(i + 1);
		}
		int root = 0;
//		dfs(root);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
//		build();
		scanf("%d", &q);
		while (q--) {
			char cmd[2]; scanf("%s", cmd);
			if (cmd[0] == 'Q') {
				int id; scanf("%d", &id); id--;
				int ans = calc(id, MX);
				ans -= calc(id, MN);
				printf("%d\n", ans);
			} else if (cmd[0] == 'R') {
				int id, val; scanf("%d%d", &id, &val); id--;
				upd(id, val);
			} else assert(0);
		}
	}
	return 0;
}