#include <bits/stdc++.h>

using namespace std;

const int N = 345;

int n, m;
int t[N][N];
int row[N][N], col[N][N];
int a[N], b[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    scanf("%d", t[i] + j);
    t[i][j]--;
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    row[i][j] = t[i][j] / m;
    col[i][j] = t[i][j] % m;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (row[i][j] != row[i][j + 1]) {
        puts("*");
        return 0;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i + 1 < n; i++) {
      if (col[i][j] != col[i + 1][j]) {
        puts("*");
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) a[i] = t[0][i] % m;
  for (int i = 0; i < n; i++) b[i] = t[i][0] / m;
  for (int i = 0; i < m; i++) if (a[i] != i) {
    bool ok = false;
    for (int j = i + 1; j < m; j++) {
      if (a[j] == i) {
        swap(a[i], a[j]);
        ans++;
        ok = true;
        break;
      }
    }
    assert(ok);
  }
  for (int i = 0; i < n; i++) if (b[i] != i) {
    bool ok = false;
    for (int j = i + 1; j < n; j++) {
      if (b[j] == i) {
        swap(b[i], b[j]);
        ans++;
        ok = true;
        break;
      }
    }
    assert(ok);
  }
  printf("%d\n", ans);
  return 0;
}