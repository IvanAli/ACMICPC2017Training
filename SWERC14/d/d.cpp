#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

const int maxn = 10005;

int n, m;
int used[maxn];
int match[maxn];
vector<int> graph[maxn];

bool solve(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i];
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
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].eb(b);
	}
	memset(match, -1, sizeof match);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof used);
		ans += solve(i);
	}
	if (ans == n) printf("YES\n");
	else printf("NO\n");
	return 0;
}