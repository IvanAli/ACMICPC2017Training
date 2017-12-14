#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int maxn = 100005;
int T, n, m;
int t;

pair<int, pair<int, int> > q[maxn];
int from[maxn << 1];
int ans[maxn];
int sz[maxn << 1];
vector<int> bq[maxn];

void join(int u, int v) {
	int pu = from[u];
	int pv = from[v];
	if (sz[u] <= sz[v]) {
		for (int i = 0; i < bq[pu].size(); i++) {
			int que = bq[pu][i];
			int x = q[que].snd.fst, y = q[que].snd.snd;
			if (from[x] == pu && from[y] == pv) ans[que] = t;
		}
		while (!bq[pu].empty()) bq[pv].pb(bq[pu].back()), bq[pu].pop_back();
		for (int i = 0; i < n; i++) if (from[i] == pu) from[i] = pv;
		sz[v] += sz[u];
	} else {
		for (int i = 0; i < bq[pv].size(); i++) {
			int que = bq[pv][i];
			int x = q[que].snd.fst, y = q[que].snd.snd;
			if (from[x] == pv && from[y] == pu) ans[que] = t;
		}
		while (!bq[pv].empty()) bq[pu].pb(bq[pv].back()), bq[pv].pop_back();
		for (int i = 0; i < n; i++) if (from[i] == pv) from[i] = pu;
		sz[u] += sz[v];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		t = 1;
		for (int i = 0; i < m; i++) ans[i] = -1;
		for (int i = 0; i < n + m; i++) from[i] = i;
		for (int i = 0; i < n + m; i++) sz[i] = 1;
		for (int i = 0; i < m; i++) {
			int type, u, v;
			cin >> type >> u >> v;
			u--, v--;
			if (type == 2) bq[from[u]].pb(i), bq[from[v]].pb(i);
			q[i] = {type, {u, v}};
		}
		for (int i = 0; i < m; i++) {
			int type = q[i].fst, u = q[i].snd.fst, v = q[i].snd.snd;
			if (type == 1) join(u, v);
			t++;
		}
		for (int i = 0; i < m; i++) {
			int type = q[i].fst, u = q[i].snd.fst, v = q[i].snd.snd;
			if (type == 2) cout << ans[i] << endl;
		}
	}
	return 0;
}
