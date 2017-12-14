#include <bits/stdc++.h>

using namespace std;

const int N = 555;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, f, p;
char grid[N][N];
int used[N][N];
long long noise[N][N];
int x[N * N], y[N * N], z[N * N];

int main() {
  scanf("%d %d %d %d", &n, &m, &f, &p);
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  int cc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ('A' <= grid[i][j] && grid[i][j] <= 'Z') {
        int s = 0, e = 1;
        cc++;
        int c = (grid[i][j] - 'A' + 1) * f;
        x[s] = i;
        y[s] = j;
        z[s] = c;
        used[i][j] = cc;
        while (s < e) {
          noise[x[s]][y[s]] += z[s];
          if (z[s] >= 2) for (int k = 0; k < 4; k++) {
            int xk = x[s] + dx[k];
            int yk = y[s] + dy[k];
            if (xk >= 0 && yk >= 0 && xk < n && yk < m) {
              if (grid[xk][yk] != '*' && used[xk][yk] != cc) {
                used[xk][yk] = cc;
                x[e] = xk;
                y[e] = yk;
                z[e] = z[s] / 2;
                e++;
              }
            }
          }
          s++;
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