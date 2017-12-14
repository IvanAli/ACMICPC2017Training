#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 100005;

int T;
int n, m;
vector<int> graph[maxn];
int used[maxn];
int low[maxn];
int from[maxn];
int timer;
vector<pair<int, int> > bridges;
int memo[maxn], was[maxn];
vector<int> tree[maxn];

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

void dfs(int u = 0, int f = 0) {
	used[u] = low[u] = timer++;
	for (auto to : graph[u]) {
		if (to == f) continue;
		if (used[to] == -1) {
			dfs(to, u);
			low[u] = min(low[u], low[to]);
			if (low[to] > used[u]) {
				bridges.pb({u, to});
			} else {
				int x = find(u), y = find(to);
				if (x != y) from[x] = y;
			}
		}
		else low[u] = min(low[u], used[to]);
	}
}

int go(int u, int f) {
	int ret = 0;
	if (was[u] != -1) return was[u];
	for (auto to : tree[u]) {
		if (to == f) continue;
		ret = max(ret, 1 + go(to, u));
	}
	return was[u] = ret;
}

int solve(int u, int f) {
	int ret = 0;
	int fst = -1, snd = -1;
	if (memo[u] != -1) return memo[u];
	for (auto to : tree[u]) {
		if (to == f) continue;
		int len = go(to, u);
		ret = max(ret, 1 + len);
		if (len > fst) snd = fst, fst = len;
		else snd = max(snd, len);
		ret = max(ret, solve(to, u));
	}
	int ok = 0;
	if (fst > -1) ok++;
	if (snd > -1) ok++;
	if (ok == 2) ret = max(ret, 2 + fst + snd);
	return memo[u] = ret;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) graph[i].clear(), tree[i].clear();
		memset(used, -1, sizeof(int) * n);
		memset(memo, -1, sizeof memo);
		memset(was, -1, sizeof was);
		timer = 0;
		bridges.clear();
		for (int a, b, i = 0; i < m; i++) cin >> a >> b, a--, b--, graph[a].pb(b), graph[b].pb(a);
		for (int i = 0; i < n; i++) from[i] = i;
		dfs();
		int root = -1;
		for (int i = 0; i < bridges.size(); i++) {
			int u = bridges[i].fst, v = bridges[i].snd;
			int x = find(u), y = find(v);
			if (root == -1) root = x;
			tree[x].pb(y);
			tree[y].pb(x);
		}
		int ans = bridges.size() - solve(root, root);
		cout << ans << endl;
	}
	return 0;
}
