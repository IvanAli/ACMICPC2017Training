#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct edge {
	int s, f, t;
	edge() {}
	edge(int s, int f, int t) : s(s), f(f), t(t) {}
};

int n, m;
int tt[505][505];
int d[505][505];
vector<int> graph[505];
vector<edge> e;
int lef[505], vis[505];
int p[505];

bool match(int u) {
	if (u == -1) return true;
	for (int i = 0; i < graph[u].size(); i++) {
		int to = graph[u][i];
		if (vis[to]) continue;
		vis[to] = true;
		if (match(lef[to])) {
			lef[to] = u;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = tt[i][j] = 10000005;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		cin >> tt[i][j];
		d[i][j] = tt[i][j];
		if (i != j) d[i][j] += p[j];
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	for (int i = 0; i < m; i++) {
		int s, f, t;
		cin >> s >> f >> t;
		s--, f--;
		e.pb({s, f, t});
	}
	for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
		if (i == j) continue;
		int si, fi, ti, sj, fj, tj;
		si = e[i].s, fi = e[i].f, ti = e[i].t;
		sj = e[j].s, fj = e[j].f, tj = e[j].t;
		if (ti + tt[si][fi] + p[fi] + d[fi][sj] <= tj) graph[i].pb(j);
	}
	int ans = 0;
	memset(lef, -1, sizeof lef);
	for (int i = 0; i < m; i++) {
		memset(vis, 0, sizeof vis);
		ans += match(i);
	}
	cout << m - ans << endl;
	return 0;
}
