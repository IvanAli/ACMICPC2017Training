#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1005;

int n;
vector<int> graph[maxn];
int used[maxn];
int x[maxn], y[maxn], r[maxn];
int vis[maxn];

bool dfs(int u = 0, int color = 0) {
	used[u] = color;
	for (auto to : graph[u]) {
		if (used[to] == -1) {
			if (!dfs(to, color ^ 1)) return false;
		} else if (used[to] == used[u]) {
			return false;
		}
	}
	return true;
}

long long dist(int i, int j) {
	return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i];
	memset(used, -1, sizeof used);
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
		long long d = dist(i, j);
		if ((long long)(r[i] + r[j]) * (r[i] + r[j]) == d) graph[i].pb(j), graph[j].pb(i);
	}
	bool ans = dfs();
	if (!ans) cout << "The input gear cannot move." << endl;
	else {
		if (used[n - 1] == -1) cout << "The input gear is not connected to the output gear." << endl;
		else {
			long long gc = gcd(r[0], r[n - 1]);
			if (used[n - 1] != used[0]) cout << '-';
			cout << r[0] / gc << ":" << r[n - 1] / gc << endl;
		}
	}
	return 0;
}
