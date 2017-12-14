#include <bits/stdc++.h>

using namespace std;

const int N = 555;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, f, p;
char grid[N][N];
int used[N][N];
long long noise[N][N];

int main() {
  scanf("%d %d %d %d", &n, &m, &f, &p);
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ('A' <= grid[i][j] && grid[i][j] <= 'Z') {
        queue<pair<pair<int, int>, int> > q;
        cc++;
        int c = (grid[i][j] - 'A' + 1) * f;
        q.push(make_pair(make_pair(i, j), c));
        used[i][j] = cc;
        while (!q.empty()) {
          auto ft = q.front(); q.pop();
          int x = ft.first.first, y = ft.first.second, z = ft.second;
          noise[x][y] += z;
          if (z >= 2) for (int k = 0; k < 4; k++) {
            int xk = x + dx[k];
            int yk = y + dy[k];
            if (xk >= 0 && yk >= 0 && xk < n && yk < m) {
              if (grid[xk][yk] != '*' && used[xk][yk] != cc) {
                used[xk][yk] = cc;
                q.push(make_pair(make_pair(xk, yk), z / 2));
              }
            }
          }
        }
      }
    }
  } 
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += (noise[i][j] > p);
    }
  }
  printf("%d\n", ans);
  return 0;
}