#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const int N = 35;

int T;
int n, m;
char grid[N][N];
int used[N][N];
int which = -1;
int cc;

void dfs(int x, int y) {
  used[x][y] = cc;
  for (int k = 0; k < 4; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (xk < 0 || xk >= n || yk < 0 || yk >= m) {
      if (which > -1 && which != cc) assert(0);
      which = cc;
      continue;
    }
    if (!used[xk][yk] && grid[xk][yk] == '0') dfs(xk, yk);
  }
}

int main() {
  scanf("%d", &T);
  while (T--) {
    memset(used, 0, sizeof used);
    int ans = 0;
    cc = 1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (!used[i][j] && grid[i][j] == '0') {
        dfs(i, j);
        cc++;
      }
    }
    assert(which > -1);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (used[i][j] == which) ans++;
    printf("%d\n", ans);
  }
  return 0;
}
