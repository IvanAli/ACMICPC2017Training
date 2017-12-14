#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 200005;

int n, a, b;
vector<int> graph[maxn];
int used[maxn];
int tin[maxn];
int sz;
vector<int> ts;

bool dfs(int u) {
	used[u] = 1;
	for (auto to : graph[u]) {
		if (used[to] == 1) return true;
		if (used[to] == 0 && dfs(to)) return true;
	}
	used[u] = 2;
	ts.pb(u);
	return false;
}

int main() {
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) graph[i * 2].pb(i * 2 + 1);
	for (int i = 0; i < a; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		graph[x * 2 + 1].pb(y * 2);
	}
	for (int i = 0; i < b; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		graph[x * 2].pb(y * 2 + 1);
		graph[y * 2].pb(x * 2 + 1);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i * 2] && dfs(i * 2)) return cout << "NO" << endl, 0;
		if (!used[i * 2 + 1] && dfs(i * 2 + 1)) return cout << "NO" << endl, 0;
	}
	cout << "YES" << endl;
	reverse(ts.begin(), ts.end());
	for (auto t : ts) tin[t] = sz++;
	for (int i = 0; i < n; i++) cout << tin[i * 2] << " " << tin[i * 2 + 1] << endl;
	return 0;
}
