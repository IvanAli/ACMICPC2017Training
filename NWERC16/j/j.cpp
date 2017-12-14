#include <bits/stdc++.h>
using namespace std;

const int inf = 1 << 28;
const int s = 0;
const int t = 1832;
const int dvert = 1802;
const int maxn = 1833;

int n, m, q;
int sz;
int graph[maxn][maxn];
int used[maxn], from[maxn];
int which[maxn], cap[maxn], prv[maxn];
int have[105];

int get() {
	memset(used, 0, sizeof used);
	memset(from, -1, sizeof from);
	queue<int> q;
	q.push(s);
	used[s] = 1;
	int v;
	while (!q.empty()) {
		v = q.front(); q.pop();
		for (int to = 1; to < maxn; to++) if (!used[to] && graph[v][to] > 0) {
			used[to] = 1;
			from[to] = v;
			if (to == t) break;
			q.push(to);
		}
	}
	v = t;
	int ret = inf;
	while (from[v] > -1) {
		int p = from[v];
		ret = min(ret, graph[p][v]);
		v = p;
	}
	if (ret == inf) return 0;
	v = t;
	while (from[v] > -1) {
		int p = from[v];
		graph[p][v] -= ret;
		graph[v][p] += ret;
		v = p;
	}
	return ret;
}

int dfs(int v = 0, int mn = inf) {
	if (v == t) return mn;
	used[v] = 1;
	for (int to = 0; to < maxn; to++) {
		if (!used[to] && graph[v][to]) {
			int ret = dfs(to, min(mn, graph[v][to]));
			if (ret > 0 && ret < inf) {
				graph[v][to] -= ret;
				graph[to][v] += ret;	
				return ret;
			}
		}
	}
	return 0;
}

int solve() {
	int ret = 0;
	while (true) {
		memset(used, 0, sizeof used);
		int flow = dfs();
//		int flow = get();
		if (flow == 0) break;
		ret += flow;
	}
	return ret;
}

int main() {
	scanf("%d%d%d", &n, &q, &m);
	sz = 1;
	for (int i = 0; i < m; i++) scanf("%d", &which[i]), which[i]--;
	for (int i = 0; i < q; i++) scanf("%d", &cap[i]);
	memset(prv, -1, sizeof prv);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		int d; scanf("%d", &d);
		memset(have, 0, sizeof have);
		for (int j = 0; j < m; j++) {
			int foo; scanf("%d", &foo);
			tot += foo;
			if (!have[which[j]]) {
				have[which[j]] = sz;
				graph[s][sz] = foo;
				if (prv[j] > -1) graph[prv[j]][sz] = inf;
				graph[sz][sz + 1] = cap[which[j]];
				sz++;
				prv[j] = sz;
				graph[sz++][dvert + i] = inf; 
			} else {
				graph[s][have[which[j]]] += foo;				
			}
		}
		graph[dvert + i][t] = d;
	}
	int ans = solve();
	if (ans == tot) printf("possible\n");
	else printf("impossible\n");
	return 0;
}