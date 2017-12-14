#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int a, b, e, p;
vector<int> graph[5005];
int used[5005];
int bet[5005], wor[5005];
set<int> gg[5005];

void dfs(int u) {
	used[u] = 1;
	for (auto to : graph[u]) {
		gg[u].insert(to);
		if (!used[to]) {
			dfs(to);
		}
		for (auto to2 : gg[to]) gg[u].insert(to2);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> a >> b >> e >> p;
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].pb(y);
	}
	for (int i = 0; i < e; i++) if (!used[i]) dfs(i);
	int aa = 0, bb = 0, cc = 0;
	for (int i = 0; i < e; i++) {
		for (auto to : gg[i]) {
			bet[i]++;
			wor[to]++;
		}
	}
	for (int i = 0; i < e; i++) {
		if (bet[i] >= e - a) aa++;
		if (bet[i] >= e - b) bb++;
		if (wor[i] >= b) cc++;
	}
	cout << aa << endl;
	cout << bb << endl;
	cout << cc << endl;
	return 0;
}
