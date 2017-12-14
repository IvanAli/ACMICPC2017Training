#include <bits/stdc++.h>

using namespace std;

const int N = 25;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
char grid[N][N];
int used[N][N];

void dfs(int x, int y) {
  used[x][y] = 1;
  for (int k = 0; k < 4; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (xk < 0 || xk >= n || yk < 0 || yk >= m) continue;
    if (!used[xk][yk] && grid[xk][yk] == '.') dfs(xk, yk);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d: ", tc + 1);
    memset(used, 0, sizeof used);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);
    int cc = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (!used[i][j] && grid[i][j] == '.') {
        dfs(i, j);
        cc++;
      }
    }
    if (cc == 2) puts("Zero");
    else if (cc == 3) puts("Eight");
    else assert(0);
  }
  return 0;
}