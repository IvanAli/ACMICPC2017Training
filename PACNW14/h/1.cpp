#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 5005;

int T;
int n, m;
int a[N];
int mem[N][105];

int solve(int cur = n, int depth = 0) {
	if (cur < 0) return -(1 << 30);
	if (cur == 0) return 0;
	int ret = -(1 << 30);
	if (mem[cur][depth] != -1) return mem[cur][depth];
	for (int j = 0; j < m; j++) {
		int res = solve(cur - (depth + 1) * a[j], depth + 1);
		if (res >= 0) ret = max(ret, res + a[j]);
	}
	return mem[cur][depth] = ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(mem, -1, sizeof mem);
		for (int i = 0; i < m; i++) scanf("%d", a + i);
		int ans = solve();
		printf("%d\n", max(-1, ans));
	}
	return 0;
}