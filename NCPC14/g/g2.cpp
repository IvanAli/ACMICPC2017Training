#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n, k;
int from[maxn];
int large[maxn], small[maxn];
int dp[maxn][maxn << 1];
int graph[maxn];
int cc;

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

int go(int s) {
	int x = s, y = s;
	x = graph[x];
	y = graph[graph[y]];
	while (x != y) {
		x = graph[x];
		y = graph[graph[y]];
	}
	int ret = 1;
	x = graph[x];
	while (x != y) {
		x = graph[x];
		ret++;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) from[i] = i;
	for (int i = 0; i < n; i++) {
		int j; scanf("%d", &j); j--;
		graph[i] = j;
		int x = find(i), y = find(j);
		if (from[x] != from[y]) {
			from[x] = y;
		}
	}
	for (int i = 0; i < n; i++) {
		int where = find(i);
		large[where]++;
		if (where == i) small[where] = go(i), cc++;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j]) {
				dp[i + 1][j + small[i]]++;
				dp[i + 1][j + large[i] + 1]--; 
				if (small[i] > 0) {
					dp[i + 1][j]++;
					dp[i + 1][j + 1]--;
				}
			}
			dp[i + 1][j + 1] += dp[i + 1][j];
		}
	}
	for (int i = k; i >= 0; i--) {
		if (dp[n][i]) return printf("%d\n", i), 0;
	}
	return 0;
}