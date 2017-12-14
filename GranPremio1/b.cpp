#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 1000005;

int T, n, q;
// vector<int> lef[maxn << 2], rig[maxn << 2];
vector<vector<int>> lef, rig;
vector<int> a;
int sz;
map<int, int> ma, mb;

void build(vector<int>::iterator b, vector<int>::iterator e, int id = 1, int l = 0, int r = sz - 1) {
	if (l == r) return;
	int mid = l + r >> 1;
	for (auto it = b; it != e; it++) {
		if (lef[id].empty()) lef[id].pb(*it <= mid);
		else lef[id].pb(lef[id].back() + (*it <= mid));
		if (rig[id].empty()) rig[id].pb(*it > mid);
		else rig[id].pb(rig[id].back() + (*it > mid));
	}
	auto p = stable_partition(b, e, [=](int i) { return i <= mid; });
	build(b, p, id << 1, l, mid);
	build(p, e, id << 1 | 1, mid + 1, r);
}

int query(int x, int y, int k, int id = 1, int l = 0, int r = sz - 1) {
	if (l == r) return l;
	int mid = l + r >> 1;
	int cnt = lef[id][y] - (x > 0 ? lef[id][x - 1] : 0);
	if (k <= cnt) return query(x > 0 ? lef[id][x - 1] : 0, lef[id][y] - 1, k, id << 1, l, mid);
	else return query(x > 0 ? rig[id][x - 1] : 0, rig[id][y] - 1, k - cnt, id << 1 | 1, mid + 1, r);
}

int main() {
	while (scanf("%d%d", &n, &q) != EOF) {
		a = vector<int>(n);
		ma.clear();
		mb.clear();
		sz = 0;
		for (int i = 0; i < n; i++) scanf("%d", &a[i]), ma[a[i]];
		for (auto &it : ma) it.snd = sz, mb[sz] = it.fst, sz++;
		for (int i = 0; i < n; i++) a[i] = ma[a[i]];
		lef = vector<vector<int>>(maxn << 2);
		rig = vector<vector<int>>(maxn << 2);
		build(a.begin(), a.end());
		while (q--) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k); l--; r--;
			int ans = query(l, r, k);
			printf("%d\n", mb[ans]);
		}
	}
	return 0;
}