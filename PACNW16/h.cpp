#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
char grid[55][55];
int used[55][55];

void dfs(int x, int y) {
	used[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int xk = x + dx[k];
		int yk = y + dy[k];
		if (xk < 0 || xk >= n || yk < 0 || yk >= m) continue;
		if ((grid[xk][yk] == 'L' || grid[xk][yk] == 'C') && 
!used[xk][yk]) dfs(xk, yk);
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> grid[i];
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (grid[i][j] == 'L' && !used[i][j]) {
			dfs(i, j);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}