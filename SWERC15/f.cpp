#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int inf = 1e9;

int n, m, a, b;
vector<int> graph[2505];
int res[2505][2505];
char grid[55][55];
int s, t;

int find() {
	queue<int> q;
	int used[2505];
	int from[2505];
	memset(used, 0, sizeof used);
	memset(from, -1, sizeof from);
	q.push(0);
	used[0] = 1;
	bool ok = false;
	while (!ok && !q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : graph[cur]) {
			if (res[cur][nxt] > 0 && !used[nxt]) {
				used[nxt] = 1;
				from[nxt] = cur;
				if (nxt == t) {
					ok = true;
					break;
				}
				q.push(nxt);
			}
		}
	}
	if (!ok) return 0;
	int ret = inf;
	int tmp = t;
	while (from[tmp] > -1) {
		ret = min(ret, res[from[tmp]][tmp]);
		tmp = from[tmp];
	}
	tmp = t;
	while (from[tmp] > -1) {
		res[from[tmp]][tmp] -= ret;
		res[tmp][from[tmp]] += ret;
		tmp = from[tmp];
	}
	if (ret == inf) return 0;
	return ret;
}

int mincut() {
	int maxflow = 0;
	while (true) {
		int flow = find();
		if (flow == 0) break;
		maxflow += flow;
	}
	return maxflow;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> a >> b;
	s = 0, t = n * m + 1;
	for (int i = 0; i < n; i++) cin >> grid[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (grid[i][j] == '.') res[s][i * m + j + 1] = b, graph[s].pb(i * m + j + 1);
		if (grid[i][j] == '#') res[i * m + j + 1][t] = b, graph[i * m + j + 1].pb(t);
		if (j < m - 1) res[i * m + j + 1][i * m + j + 2] = res[i * m + j + 2][i * m + j + 1] = a, graph[i * m + j + 1].pb(i * m + j + 2), graph[i * m + j + 2].pb(i * m + j + 1);
		if (i < n - 1) res[i * m + j + 1][i * m + m + j + 1] = res[i * m + m + j + 1][i * m + j + 1] = a, graph[i * m + j + 1].pb(i * m + m + j + 1), graph[i * m + m + j + 1].pb(i * m + j + 1);
	}
	int ans = mincut();
	cout << ans << endl;
	return 0;
}
