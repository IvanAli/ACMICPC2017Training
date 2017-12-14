#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

const int N = 100005;

int n, m;
vector<int> graph[N], tgraph[N];
int used[N];
int scc;
map<int, int> dist[N];
int dp[N];
int com[N];
vector<int> ts;

void dfs(int v) {
	used[v] = 1;
	for (auto to : graph[v]) if (!used[to]) dfs(to);
	ts.pb(v);
}

void tdfs(int v) {
	com[v] = scc;
	for (auto to : tgraph[v]) if (com[to] == -1) tdfs(to);
}

void calc(int s, int v, int len = 0) {
	used[v] = 1;
	for (auto to : graph[v]) if (!used[to]) {
		dist[s][to] = max(dist[s][to], len + 1);
		if (com[s] == com[to]) {
			
			calc(s, to, len + 1);
		}
	}
	used[v] = 0;
}

int mem[N];
bool was[N];

int solve(int v) {
	if (mem[v] > -1) return mem[v];
	int ret = 0;
	was[v] = 1;
	for (auto p : dist[v]) {
		int to = p.fst, d = p.snd;
		ret = max(ret, d);
		if (com[v] != com[to]) ret = max(ret, d + solve(to));
//		else if (!was[to]) ret = max(ret, solve(to)); 
	}
	return mem[v] = ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b); a--, b--;
		graph[a].pb(b);
		tgraph[b].pb(a);
	}
	for (int i = 0; i < n; i++) if (!used[i]) dfs(i);
	reverse(ts.begin(), ts.end());
	fill(com, com + n, -1);
	for (auto v : ts) if (com[v] == -1) tdfs(v), scc++;
	fill(used, used + n, 0);
	for (int i = 0; i < n; i++) calc(i, i);
	int ans = 0;
	/*for (auto v : ts) {
		for (auto u : dist[v]) {
			int to = u.fst, d = u.snd;
			assert(com[v] == com[to]);
			for (auto toto : graph[to]) {
				if (com[to] != com[toto]) {
					dp[toto] = max(dp[toto], dp[v] + d + 1);
				}
			}
		}
		for (auto to : graph[v]) if (com[v] != com[to]) {
			dp[to] = max(dp[to], dp[v] + 1);
		}
	}*/
	memset(mem, -1, sizeof mem);
	for (int i = 0; i < n; i++) ans = max(ans, solve(i));
	printf("%d\n", ++ans);
	return 0;
}