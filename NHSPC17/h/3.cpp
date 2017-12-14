#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const int mod = 1e9 + 7;

int T;
int n;
vector<pair<int, int>> graph[N];
int size[N];
long long dp[N];
long long weight[N];

int add(int a, int b) {
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int sub(int a, int b) {
	int ret = a - b;
	if (ret < 0) ret += mod;
	return ret;
}

int mul(int a, int b) {
	return (long long)a * b % mod;
}

void calc(int v = 0, int p = 0) {
	size[v] = 1;
	weight[v] = 0;
	for (auto nxt : graph[v]) {
		int to = nxt.fst, w = nxt.snd;
		if (to == p) continue;
		calc(to, v);
		size[v] += size[to];
		weight[v] = add(weight[v], weight[to]);
		weight[v] = add(weight[v], mul(w, size[to]));
	}
}

void dfs(int v = 0, int p = 0) {
	dp[v] = 0;
	for (auto nxt : graph[v]) {
		int to = nxt.fst, w = nxt.snd;
		if (to == p) continue;
		dfs(to, v);
		dp[v] = add(dp[v], dp[to]);
		dp[v] = add(dp[v], mul(w, mul(size[to], sub(size[v], size[to]))));
		dp[v] = add(dp[v], mul(weight[to], sub(size[v], size[to])));
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d: ", tc + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) graph[i].clear();
		for (int i = 0; i + 1 < n; i++) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w); a--, b--;
			graph[a].pb({b, w});
			graph[b].pb({a, w});
		}
		calc();
		dfs();
		int ans = 0;
		for (int i = 0; i < n; i++) ans = add(ans, dp[i]);
		printf("%d\n", ans);
	}
	return 0;
}