#include <bits/stdc++.h>

using namespace std;

const int N = 777;

int n, m, q;
bool anc[N][N];
char cmd[2];
int age[N];

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%d", age + i);
  for (int i = 0; i < m; i++) {
    int x, y; scanf("%d %d", &x, &y); x--, y--;
    anc[x][y] = 1;
  }
  for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (i != j) anc[i][j] |= (anc[i][k] & anc[k][j]);
  }
  while (q--) {
    scanf("%s", cmd);
    if (cmd[0] == 'T') {
      int a, b; scanf("%d %d", &a, &b); a--, b--;
      for (int i = 0; i < n; i++) {
        int tmp = anc[i][a];
        anc[i][a] = anc[i][b];
        anc[i][b] = tmp;
      }
      swap(anc[a], anc[b]);
    } else if (cmd[0] == 'P') {
      int x; scanf("%d", &x);
      x--;
      int ans = 1 << 30;
      for (int i = 0; i < n; i++) {
        if (anc[i][x]) ans = min(ans, age[i]);
      }
      if (ans == 1 << 30) puts("*");
      else printf("%d\n", ans);
    }
  }
  return 0;
}