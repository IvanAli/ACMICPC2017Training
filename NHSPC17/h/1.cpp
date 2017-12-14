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
int depth[N];

void calc(int v = 0, int p = 0) {
	size[v] = 1;
	for (auto nxt : graph[v]) {
		int to = nxt.fst;
		if (to == p) continue;
		depth[to] = depth[v] + 1;
		calc(to, v);
		size[v] += size[to];
	}
}

long long add(long long a, long long b) {
	long long ret = a + b;
	while (ret >= mod) ret -= mod;
}

long long sub(long long a, long long b) {
	long long ret = a - b;
	while (ret < 0) ret += mod;
	return ret; 
}

long long mul(long long a, long long b) {
	return (a * b) % mod;
}

long long dfs(int v = 0, int p = 0, long long sum = n) {
	long long ret = 0;
	for (auto nxt : graph[v]) {
		int to = nxt.fst, w = nxt.snd;
		if (to == p) continue;
		ret = add(ret, mul(mul(w, size[to]), sub(sum, mul(depth[to], size[to]))));
		ret = add(ret, dfs(to, v, sum + size[to]));
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d: ", tc + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) graph[i].clear();
		fill(depth, depth + n, 0);
		fill(size, size + n, 0);
		for (int i = 0; i + 1 < n; i++) {
			int a, b, w; scanf("%d%d%d", &a, &b, &w); a--, b--;
			graph[a].pb({b, w});
			graph[b].pb({a, w});
		}
		calc();
		long long ans = dfs();
		printf("%lld\n", ans);
	}
	return 0;
}