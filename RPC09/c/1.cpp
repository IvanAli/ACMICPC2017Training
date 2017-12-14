#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

int n, m;
int used[N][N], used2[N][N];
bool possible[N][N];
char grid[N][N];
int cc;
int size[N * N];
int ans;

void dfs(int x, int y) {
  used[x][y] = 1;
  for (int k = 0; k < 8; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (xk < 0 || xk > n + 1 || yk < 0 || yk > m + 1) continue;
    if (!used[xk][yk] && grid[xk][yk] == '#') {
      grid[xk][yk] = '.';
      ans++;
    }
    if (grid[xk][yk] == '*') {
      possible[xk][yk] = true;
    }
    if (!used[xk][yk] && grid[xk][yk] == '.') {
      dfs(xk, yk);
    }
  }
}

void dfs2(int x, int y) {
  used2[x][y] = cc;
  if (grid[x][y] == '#') size[cc]++;
  for (int k = 0; k < 8; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (xk < 0 || xk > n + 1 || yk < 0 || yk > m + 1) continue;
    if (!used2[xk][yk] && grid[xk][yk] != '*') {
      dfs2(xk, yk);
    }
  }
}

int main() {
  while (scanf("%d %d", &n, &m) == 2) {
    memset(possible, 0, sizeof possible);
    memset(used, 0, sizeof used);
    memset(used2, 0, sizeof used2);
    ans = 0;
    memset(size, 0, sizeof size);
    for (int i = 1; i <= n; i++) scanf("%s", grid[i] + 1);
    for (int j = 0; j <= m + 1; j++) {
      grid[0][j] = '.';
      grid[n + 1][j] = '.';
    }
    for (int i = 0; i <= n + 1; i++) {
      grid[i][0] = '.';
      grid[i][m + 1] = '.';
    }
    dfs(0, 0);
    cc = 1;
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) {
      if (!used2[i][j] && grid[i][j] != '*') {
        dfs2(i, j);
        cc++;
      }
    }
    int tmp = ans;
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) {
      if (possible[i][j]) {
        set<int> which;
        for (int k = 0; k < 8; k++) {
          int xk = i + dx[k];
          int yk = j + dy[k];
          if (xk < 0 || xk > n + 1 || yk < 0 || yk > m + 1) continue;
          which.insert(used2[xk][yk]);
        }
        int sum = 0;
        for (auto it : which) sum += size[it];
        ans = max(ans, tmp + sum);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}