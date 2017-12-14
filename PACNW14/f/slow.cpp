#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const int mod = 1e9 + 9;

int dx[] = {1, 2, -1, -2, -2, -1, 1, 2};
int dy[] = {2, 1, 2, 1, -1, -2, -2, -1};
int T;
int n, m;
bool grid[32][32];

int add(int a, int b) {
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

bool ok(int x, int y) {
	for (int k = 0; k < 8; k++) {
		int xk = x + dx[k];
		int yk = y + dy[k];
		if (xk < 0 || xk >= n || yk < 0 || yk >= m) continue;
		if (grid[xk][yk]) return false;
	}
	return true;
}

bool solve() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j]) if (!ok(i, j)) return false;
	return true;
}

void print() {
	puts("---------");
	for (int i = 0; i < n; i++, puts("")) for (int j = 0; j < m; j++) printf("%d ", grid[i][j]);
	puts("---------");
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int ans = 0;
		for (int mask = 0; mask < 1 << (n * m); mask++) {
			memset(grid, 0, sizeof grid);
			for (int i = 0; i < n * m; i++) {
				int r = i / m;
				int c = i % m;
				if (mask & (1 << i)) {
					grid[r][c] = 1;
				} else {
					grid[r][c] = 0;
				}
			}
//			if (solve()) print();
			ans = add(ans, solve());
		}
		printf("%d\n", ans);
	}
	return 0;
}