#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 100005;

int n;
int cc[maxn], tc[maxn];
vector<int> graph[maxn];
vector<int> tgraph[maxn];
int p[maxn];
int com[maxn], used[maxn];
vector<int> ts;
int scc;
int size[maxn];

void dfs(int u) {	
	used[u] = 1;
	for (auto to : graph[u]) {
		if (used[to]) continue;
		dfs(to);
	}
	ts.pb(u);
}

void tdfs(int u) {
	com[u] = scc;
	for (auto to : tgraph[u]) {
		if (com[to] > -1) continue;
		tdfs(to);
	}
}


int main() {
	freopen("codecoder.in", "r", stdin);
	freopen("codecoder.out", "w+", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> cc[i] >> tc[i];
	for (int i = 0; i < n; i++) p[i] = i;
	sort(p, p + n, [&](int i, int j) { return cc[i] < cc[j]; });
	for (int i = 0; i + 1 < n; i++) graph[p[i + 1]].pb(p[i]);
	sort(p, p + n, [&](int i, int j) { return tc[i] < tc[j]; });
	for (int i = 0; i + 1 < n; i++) graph[p[i + 1]].pb(p[i]);
	for (int i = 0; i < n; i++) if (!used[i]) dfs(i);
	reverse(ts.begin(), ts.end());
	for (int i = 0; i < n; i++) for (auto to : graph[i]) tgraph[to].pb(i);
	memset(com, -1, sizeof com);
	for (auto t : ts) {
		if (com[t] == -1) {
			tdfs(t), scc++;
		}
	}
	for (int i = 0; i < n; i++) size[com[i]]++;
	for (int i = scc - 1; i > 0; i--) size[i - 1] += size[i];
	for (int i = 0; i < n; i++) cout << size[com[i]] - 1 << endl;
	return 0;
}