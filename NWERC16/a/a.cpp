#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;

const int inf = 1 << 25;

int n, m;
char a[45][405];
char sol[45][405];
int memo[45][45][405][15];

int solve(int b = 0, int e = n, int it = 0, int d = 0) {
	if (it == m) return 0;
	if (b == e) return 0;
	if (d > 9) return inf;
	if (memo[b][e][it][d] != -1) return memo[b][e][it][d];
	int t = 0;
	int ret = inf;
	int res;
	res = solve(b, e, it, d + 1);
	if (res < ret) {
		ret = res;
	}
	for (int i = b; i < e; i++) {
		if (a[i][it] - '0' != d) t++;
		res = t + solve(b, i + 1, it + 1, 0) + solve(i + 1, e, it, d + 1);
		if (res < ret) {
			ret = res;
		}
	}
	return memo[b][e][it][d] = ret;
}

void build(int b = 0, int e = n, int it = 0, int d = 0) {
	if (it == m) return;
	if (b == e) return;
	if (d > 9) return;
	int t = 0;
	int ret = inf;
	int res;
	res = solve(b, e, it, d + 1);
	if (memo[b][e][it][d] == res) {
		build(b, e, it, d + 1);
		return;
	}
	for (int i = b; i < e; i++) {
		if (a[i][it] - '0' != d) t++;
		res = t + solve(b, i + 1, it + 1, 0) + solve(i + 1, e, it, d + 1);
		if (memo[b][e][it][d] == res) {
			for (int j = b; j <= i; j++) sol[j][it] = d + '0';
			build(b, i + 1, it + 1, 0);
			build(i + 1, e, it, d + 1);
			break;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", a[i]);
	memset(memo, -1, sizeof memo);
//	int ans = solve();
//	printf("ANS: %d\n", ans);
	solve();
	build();
	for (int i = 0; i < n; i++, putchar('\n')) for (int j = 0; j < m; j++) putchar(sol[i][j]); 
	return 0;
}