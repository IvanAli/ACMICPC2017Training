#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 100005;

int n, m, k;
int iron[maxn];
int coal[maxn];
vector<int> graph[maxn];
vector<int> tgraph[maxn];
int dist[maxn], disti[maxn], distc[maxn];

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
			tgraph[to].pb(i);
		}
	}
	queue<int> q;
	q.push(0);
	memset(dist, -1, sizeof dist);
	dist[0] = 0;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (auto to : graph[v]) {
			if (dist[to] == -1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	queue<int> qi, qc;
	memset(disti, -1, sizeof disti);
	memset(distc, -1, sizeof distc);
	for (int i = 0; i < n; i++) {
		if (iron[i]) qi.push(i), disti[i] = 0;
		if (coal[i]) qc.push(i), distc[i] = 0;
	}
	while (!qi.empty()) {
		int v = qi.front(); qi.pop();
		for (auto to : tgraph[v]) {
			if (disti[to] == -1 || disti[to] > disti[v] + 1) {
				disti[to] = disti[v] + 1;
				qi.push(to);
			}
		}
	}
	while (!qc.empty()) {
		int v = qc.front(); qc.pop();
		for (auto to : tgraph[v]) {
			if (distc[to] == -1 || distc[to] > distc[v] + 1) {
				distc[to] = distc[v] + 1;
				qc.push(to);
			}
		}
	}
	int ans = 1 << 29;
	for (int i = 0; i < n; i++) {
		int res;
		if (dist[i] == -1) res = 1 << 29;
		else res = dist[i];
		if (disti[i] == -1) res += 1 << 29;
		else res += disti[i];
		if (distc[i] == -1) res += 1 << 29;
		else res += distc[i];
		ans = min(ans, res);
	}
	if (ans == 1 << 29) printf("impossible\n");
	else printf("%d\n", ans);
	return 0;
}