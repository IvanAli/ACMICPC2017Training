#include <bits/stdc++.h>
#define pb push_back
using namespace std;


const int maxn = 10005;

int n;
int scc;
vector<int> graph[maxn];
vector<int> tgraph[maxn];
set<int> cgraph[maxn];
int rev[maxn];
int used[maxn];
int com[maxn];
int all[maxn][2];
int size[maxn];
vector<int> ts;

void dfs(int u) {
	used[u] = 1;
	for (auto to : graph[u]) {
		if (!used[to]) dfs(to);
	}
	ts.pb(u);
}

void dfs2(int u) {
	used[u] = 1;
	for (auto to : graph[u]) {
//		if (used[to]) continue;
		if (com[u] != com[to]) cgraph[com[u]].insert(com[to]);
		if (!used[to]) dfs2(to); 
	}
}


void tdfs(int u) {
	com[u] = scc;
	for (auto to : tgraph[u]) {
		if (com[to] == -1) tdfs(to);
	}
}

void cdfs(int u) {
	used[u] = 1;
	for (auto to : cgraph[u]) {
		if (!used[to]) cdfs(to);
	}
	ts.pb(u);
}


bool bad(int u) {
	for (auto to : graph[u]) if (u == to) return true;
	return false;
}

int main() {
//	cin >> n;
		scanf("%d", &n);
		memset(used, 0, sizeof used);
		memset(com, -1, sizeof com);
		memset(size, 0, sizeof size);
		memset(all, 0, sizeof all);
		scc = 0;
		for (int i = 0; i < n; i++) graph[i].clear(), tgraph[i].clear(), cgraph[i].clear();
		ts.clear();
		for (int i = 2; i < n; i++) {
			int k; scanf("%d", &k);
			for (int j = 0; j < k; j++) {
				int u; scanf("%d", &u);
				graph[u].pb(i);
			}
		}
		for (int i = 0; i < n; i++) if (!used[i]) dfs(i);
		memset(used, 0, sizeof used);
		reverse(ts.begin(), ts.end());
		for (int i = 0; i < n; i++) for (auto to : graph[i]) tgraph[to].pb(i);
		for (auto t : ts) if (com[t] == -1) tdfs(t), scc++;
		for (int i = 0; i < n; i++) rev[com[i]] = i;
		for (int i = 0; i < n; i++) size[com[i]]++;
		all[com[0]][0]++;
		all[com[1]][1]++;
		ts.clear();
		for (int i = 0; i < n; i++) if (!used[i]) dfs2(i);
		memset(used, 0, sizeof used);
		for (int i = 0; i < scc; i++) if (!used[i]) cdfs(i);
		reverse(ts.begin(), ts.end());
	/*	for (int i = 0; i < ts.size(); i++) {
			int cur = ts[i];
			int nxt = i + 1 < n ? ts[i + 1] : -1;
			if (size[cur] > 1 || bad(cur)) all[cur][0] = all[cur][1] = -1;
			if (nxt > -1) for (int j = 0; j < 2; j++) {
				if (all[cur][j] > -1) all[nxt][j] += all[cur][j];
				else all[nxt][j] = -1;
			}
		}
	*/
		for (auto t : ts) {
			if (size[t] > 1 || bad(rev[t])) for (int j = 0; j < 2; j++) all[t][j] = -1;
			for (auto to : cgraph[t]) for (int j = 0; j < 2; j++) {
				if (all[t][j] == -1) all[to][j] = -1;
				else all[to][j] += all[t][j];
			}
		}
		for (int i = 0; i < n; i++) {
			if (all[com[i]][0] == -1) printf("?\n");
			else if (all[com[i]][0] == all[com[i]][1]) printf("1/2\n");
			else if (all[com[i]][0] > all[com[i]][1]) printf("0\n");
			else printf("1\n");
		}
	
	
	return 0;
}