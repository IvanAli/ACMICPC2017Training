#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 200005;

int n, m;
vector<int> graph[maxn];
int used[maxn];
int cnt[2];

bool dfs(int v, bool c) {
	if (used[v] > -1) {
		if (used[v] != c) return false;
		return true;
	}
	used[v] = c;
	cnt[c]++;
	for (auto to : graph[v]) {
		if (used[to] > -1 && used[to] != (c ^ 1)) return false;
		else if (used[to] == -1 && !dfs(to, c ^ 1)) return false;
	
	}
	return true; 
}

int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	memset(used, -1, sizeof used);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--, b--;
		if (c == 0) {
			cnt[1] = 0;
			if (!dfs(a, 0)) return printf("impossible\n"), 0;
			if (!dfs(b, 0)) return printf("impossible\n"), 0;
			ans += cnt[1];
		} else if (c == 2) {
			cnt[1] = 0;
			if (!dfs(a, 1)) return printf("impossible\n"), 0;
			if (!dfs(b, 1)) return printf("impossible\n"), 0;
			ans += cnt[1];
		} else if (c == 1) {
			graph[a].pb(b);
			graph[b].pb(a);
		} else assert(0);
	}
	for (int i = 0; i < n; i++) if (used[i] > -1) {
		for (auto to : graph[i]) {
			cnt[1] = 0;
			if (!dfs(to, used[i] ^ 1)) return printf("impossible\n"), 0;
			ans += cnt[1];
		}
	}
	for (int i = 0; i < n; i++) if (used[i] == -1) {
		for (int j = 0; j < 2; j++) cnt[j] = 0;
		if (!dfs(i, 0)) return printf("impossible\n"), 0;
		ans += min(cnt[0], cnt[1]);
	}
	printf("%d\n", ans);
	return 0;
}