#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, z;
int used[N][N];
char grid[N][N];
int xs, ys, xd, yd;

bool edge(int x, int y) {
  for (int k = 0; k < 4; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (0 <= xk && xk < n && 0 <= yk && yk < m) {
      if (grid[xk][yk] == '.') return true;
    }
  }
  return false;
}

int d[N][N];

bool bfs(int x, int y) {
  queue< tuple<int, int, int> > q;
  memset(used, 0, sizeof used);
  set< pair<int, int> > start;
  q.emplace(0, x, y);
  start.insert(make_pair(x, y));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = (int) 1e9;
    }
  }
  d[x][y] = 0;
  while (!q.empty()) {
    tuple<int, int, int> ft = q.front(); q.pop();
    int t, x, y; tie(t, x, y) = ft;
    for (int k = 0; k < 4; k++) {
      int xk = x + dx[k];
      int yk = y + dy[k];
      if (0 <= xk && xk < n && 0 <= yk && yk < m) {
        if (grid[xk][yk] == 'F') {
          if (!start.count(make_pair(xk, yk)) && t + 1 <= z) {
            if (xk == xd && yk == yd) return true;
            start.insert(make_pair(xk, yk));
            q.emplace(0, xk, yk);
            if (false || z - 8 <= t + 1 && t + 1 <= z || edge(xk, yk)) {
              q.emplace(t + 1, xk, yk);
            }
          }
        } else {
          if (t + 1 < d[xk][yk]) {
            d[xk][yk] = t + 1;
            q.emplace(t + 1, x, y);
          }
        }
      }
    }
  }
  return false;
}

int main() {
  scanf("%d %d %d", &n, &m, &z);
  scanf("%d %d %d %d", &xs, &ys, &xd, &yd);
  xs--, ys--, xd--, yd--;
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  if (bfs(xs, ys)) puts("Hello, Deimos!");
  else puts("Dire victory");
  return 0;
}