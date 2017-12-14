#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, z;
char grid[N][N];
int xs, ys, xd, yd;
int d[N][N];

bool bfs(int x, int y) {
  queue< tuple<int, int> > q;
  q.emplace(x, y);
  memset(d, -1, sizeof d);
  d[x][y] = 0;
  if (xs == xd && ys == yd) return true;
  while (!q.empty()) {
    tuple<int, int> ft = q.front(); q.pop();
    int x, y; tie(x, y) = ft;
    for (int k = 0; k < 4; k++) {
      int xk = x + dx[k];
      int yk = y + dy[k];
      if (0 <= xk && xk < n && 0 <= yk && yk < m) {
        if (xk == xd && yk == yd) return true;
        if (grid[xk][yk] == 'F') {
          if (d[xk][yk] == -1) {
            d[xk][yk] = 0;
            q.emplace(xk, yk);
          }
        } else if (grid[xk][yk] == '.') {
          if (d[xk][yk] == -1 || d[x][y] + 1 < d[xk][yk]) {
            d[xk][yk] = d[x][y] + 1;
            if (d[xk][yk] < z) {
              q.emplace(xk, yk);
            }
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