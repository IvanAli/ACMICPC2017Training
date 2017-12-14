#include <bits/stdc++.h>
#define time sidfnisndfs
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 100005;
const int inf = 1 << 30;

int n, q;
vector<int> graph[maxn];
int up[maxn][30];
pair<int, int> segtree[maxn << 3];
int cov[maxn];
int size[maxn];
int tin[maxn], tout[maxn];
int p[maxn];
int depth[maxn];
int time;

void dfs(int u = 0) {
	tin[u] = time++;
	for (auto to : graph[u]) {
		depth[to] = depth[u] + 1;
		dfs(to);
		size[u] += size[to];
	}
	if (size[u] == 0) size[u] = 1;
	tout[u] = time++;
}


void update(int val, int p, int id = 1, int l = 0, int r = time) {
	if (l + 1 == r) {
		if (val > -1) segtree[id] = {val, val};
		else segtree[id] = {inf, -inf};
		return;
	}
	int mid = l + r >> 1;
	if (p < mid) update(val, p, id << 1, l, mid);
	else update(val, p, id << 1 | 1, mid, r);
	if (segtree[id << 1].fst == inf) segtree[id] = segtree[id << 1 | 1];
	else if (segtree[id << 1 | 1].fst == inf) segtree[id] = segtree[id << 1];
	else segtree[id].fst = tin[segtree[id << 1].fst] < tin[segtree[id << 1 | 1].fst] ? segtree[id << 1].fst : segtree[id << 1 | 1].fst,
	segtree[id].snd = tout[segtree[id << 1].snd] > tout[segtree[id << 1 | 1].snd] ? segtree[id << 1].snd : segtree[id << 1 | 1].snd;
}

pair<int, int> query(int x, int y, int id = 1, int l = 0, int r = time) {
	if (l >= y || r <= x) return {inf, -inf};
	if (l >= x && r <= y) return segtree[id];
	int mid = l + r >> 1;
	auto lef = query(x, y, id << 1, l, mid);
	auto rig = query(x, y, id << 1 | 1, mid, r);
	pair<int, int> ret;
	if (lef.fst == inf) ret = rig;
	else if (rig.fst == inf) ret = lef;
	else ret.fst = tin[lef.fst] < tin[rig.fst] ? lef.fst : rig.fst,
	ret.snd = tout[lef.snd] > tout[rig.snd] ? lef.snd : rig.snd;
	return ret;
}

int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	int log = 1;
	for (log; 1 << log <= depth[x]; log++);
	log--;
	for (int i = log; i >= 0; i--) {
		if (depth[x] - (1 << i) >= depth[y]) x = up[x][i];
	}
	if (x == y) return x;
	for (int i = log; i >= 0; i--) {
		if (up[x][i] != -1) {
			if (up[x][i] != up[y][i]) x = up[x][i], y = up[y][i];
		}
	}
	return p[x];
}


int getroot(int x) {
	int log = 1;
	for (log; 1 << log <= depth[x]; log++);
	log--;
	for (int i = log; i >= 0; i--) {
		if (up[x][i] > 0) x = up[x][i];
	}
	return x;
}

int main() {
	freopen("gangsters.in", "r", stdin);
	freopen("gangsters.out", "w+", stdout);
	cin >> n >> q;
	for (int i = 1; i < n; i++) cin >> p[i], p[i]--, graph[p[i]].pb(i);
	dfs();
	memset(up, -1, sizeof up);
	for (int i = 0; i < n; i++) up[i][0] = p[i];
	for (int j = 1; 1 << j < n; j++) for (int i = 0; i < n; i++) {
		if (up[i][j - 1] != -1) up[i][j] = up[up[i][j - 1]][j - 1];
	}
	for (int i = 0; i < time << 2; i++) segtree[i] = {inf, -inf};
	int edges = 0;
	int gang = 0;
	int tot = 0;
	while (q--) {
		string opt; int v;
		cin >> opt >> v;
		v--;
		int root = getroot(v);
		if (opt[0] == '+') {
			update(v, tin[v]);
			gang++;
		} else if (opt[0] == '-') {
			update(-1, tin[v]);
			gang--;
		}
		auto qq = query(tin[root], tout[root]);
		if (qq.fst == inf) edges--;
		else if (qq.fst == qq.snd && opt[0] == '+') edges++;
		int ll = qq.fst < inf ? lca(qq.fst, qq.snd) : -1;
		int sz = ll > -1 ? size[ll] : 0;
		tot += sz - cov[root];
		cov[root] = sz;
		cout << edges << " " << tot - gang << endl;
	}
	return 0;
}