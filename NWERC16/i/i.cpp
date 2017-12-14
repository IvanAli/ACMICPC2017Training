#include <bits/stdc++.h>
#define pb push_back
using namespace std;
/*
void dfs(int v = 0, int ir = 0, int co = 0) {
	used[v][ir][co] = 1;
	for (auto to : graph[v]) {
		
	}
}
*/

const int maxn = 100005;

int n, m, k;
int iron[maxn];
int coal[maxn];
int used[maxn][2][2];
vector<int> graph[maxn];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int foo; scanf("%d", &foo); foo--;
		iron[foo] = 1;
	}
	for (int i = 0; i < k; i++) {
		int foo; scanf("%d", &foo), foo--;
		coal[foo] = 1;
	}
	for (int i = 0; i < n; i++) {
		int t; scanf("%d", &t);
		while (t--) {
			int to; scanf("%d", &to); to--;
			graph[i].pb(to);
		}
	}
//	dfs();
	memset(used, -1, sizeof used);
	queue<tuple<int, int, int> > q;
	if (iron[0]) {
		q.push(make_tuple(0, 1, 0));
		used[0][1][0] = 0;
	} else if (coal[0]) {
		q.push(make_tuple(0, 0, 1));
		used[0][0][1] = 0;
	} else {
		q.push(make_tuple(0, 0, 0));
		used[0][0][0] = 0;
	}
	while (!q.empty()) {
		int v, iv, cv;
		auto ft = q.front(); q.pop();
		tie(v, iv, cv) = ft;
		for (auto to : graph[v]) {
			int ito = iv, cto = cv;
			if (iron[to]) ito = max(1, ito + 1);
			if (coal[to]) cto = max(1, cto + 1);
			assert(iron[to] + coal[to] < 2);
			if (used[to][ito][cto] == -1) {
				used[to][ito][cto] = used[v][iv][cv] + 1;
				q.push(make_tuple(to, ito, cto));
			}
		}
	}
	int ans = 1 << 29;
	int ansx = 1 << 29;
	int ansy = 1 << 29;
	for (int i = 0; i < n; i++) {
		if (used[i][1][1] != -1) ans = min(ans, used[i][1][1]);
		if (used[i][0][1] != -1) ansx = min(ansx, used[i][0][1]);
		if (used[i][1][0] != -1) ansy = min(ansy, used[i][1][0]);
	}
	ans = min(ans, ansx + ansy);
	if (ans == 1 << 29) printf("impossible\n");
	else printf("%d\n", ans);
	return 0;
}