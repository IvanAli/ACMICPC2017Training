#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int a, b, e, p;
vector<int> graph[5005];
vector<int> depth[5005];
int in[5005];
int sum[5005];

int main() {
	cin >> a >> b >> e >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].pb(y);
		in[y]++;
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < e; i++) if (in[i] == 0) q.push({i, 0});
	int maxlevel = 0;
	while (!q.empty()) {
		auto top = q.front(); q.pop();
		int cur = top.first, level = top.second;
		maxlevel = max(maxlevel, level);
		depth[level].pb(cur);
		for (auto to : graph[cur]) {
			in[to]--;
			if (in[to] == 0) q.push({to, level + 1});
		}
	}
	sum[0] = depth[0].size();
	for (int i = 1; i <= maxlevel; i++) sum[i] = depth[i].size() + sum[i - 1];
	int aa = 0, bb = 0;
	int ai = -1, bi = -1;
	for (int i = 0; i <= maxlevel; i++) {
		if (sum[i] <= a) aa = sum[i], ai = i;
		if (sum[i] <= b) bb = sum[i], bi = i;
	}
	int cc = 0;
	if (bi > -1 && sum[bi] == b) cc = e - sum[bi];
	else cc = e - sum[bi + 1];
	cout << aa << endl;
	cout << bb << endl;
	cout << cc << endl;
	return 0;
}
