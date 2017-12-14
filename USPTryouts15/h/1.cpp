#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n, m;
vector<int> graph[N];
int match[N];
int color[N];
int used[N];
int have[N];

void dfs(int v = 0, int c = 1) {
	color[v] = c;
	for (auto to : graph[v]) {
		if (color[to] == -1) dfs(to, c ^ 1);
		else assert(color[v] != color[to]);
	}
}

bool solve(int v) {
	for (auto to : graph[v]) {
		if (used[to]) continue;
		used[to] = 1;
		if (match[to] == -1 || solve(match[to])) {
			match[to] = v;
			return true;
		} 
	}
	return false;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b; a--, b--;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		fill(color, color + n, -1);
		dfs();
		fill(match, match + n, -1);
		int ans = 0;
		for (int i = 0; i < n; i++) if (color[i]) {
			fill(used, used + n, 0);
			ans += solve(i);
		}
		fill(have, have + n, 0);
		for (int i = 0; i < n; i++) if (match[i] > -1) have[i] = have[match[i]] = 1;
		for (int i = 0; i < n; i++) ans += have[i] ^ 1;
		cout << ans << endl;
	}
	return 0;
}