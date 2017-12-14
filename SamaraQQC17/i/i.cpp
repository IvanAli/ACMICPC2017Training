#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 200005;

int n, m;
int used[maxn];
int color[maxn];
int least[maxn];
vector<int> graph[maxn];
int cc;
int deg[maxn];

void dfs(int v) {
	used[v] = cc;
	for (auto to : graph[v]) if (used[to] == -1) dfs(to);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].pb(b);
		graph[b].pb(a);
		deg[a]++, deg[b]++;
	}
	memset(used, -1, sizeof used);
	for (int i = 0; i < n; i++) if (used[i] == -1) least[cc] = i, dfs(i), cc++;
	for (int i = 0; i < n; i++) if (deg[least[used[i]]] > deg[i]) least[used[i]] = i;
	for (int i = 0; i < n; i++) color[i] = 1;
	int mn = 0;
	for (int i = 0; i < cc; i++) if (deg[least[i]] < deg[least[mn]]) mn = i;
	color[least[mn]] = 0;
	for (auto to : graph[least[mn]]) color[to] = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", color[i]);
	}
	printf("\n");
	return 0;
}