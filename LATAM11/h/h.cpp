#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 10005;

int n, m, q;
vector<int> graph[maxn];
vector<int> rgraph[maxn];
int tin[maxn], fup[maxn];
int com[maxn];
int timer, cc;

void dfs(int v, int f) {
	tin[v] = fup[v] = timer++;
	for (auto to : graph[v]) {
		if (to == f) continue;
		if (!tin[to]) {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) rgraph[v].pb(to), rgraph[to].pb(v);
		} else fup[v] = min(fup[v], tin[to]);
	}
}

void rdfs(int v) {
	com[v] = cc;
	for (auto to : rgraph[v]) if (com[to] == -1) rdfs(to); 
}

int main() {
	while (scanf("%d%d%d", &n, &m, &q) && n + m + q > 0) {
		timer = 1;
		cc = 0;
		memset(tin, 0, sizeof tin);
		memset(com, -1, sizeof com);
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i < n; i++) rgraph[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d%d", &a, &b), a--, b--;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		for (int i = 0; i < n; i++) if (!tin[i]) dfs(i, i);
		for (int i = 0; i < n; i++) if (com[i] == -1) rdfs(i), cc++;
		while (q--) {
			int a, b; scanf("%d%d", &a, &b), a--, b--;
			printf("%c\n", com[a] == com[b] ? 'Y' : 'N');
		}
		printf("-\n");
	}	
	return 0;
}