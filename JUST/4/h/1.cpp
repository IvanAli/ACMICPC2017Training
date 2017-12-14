#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

char s[N][N];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    int need = 0;
    for (int i = 0; i < n; i++) {
      need += s[i][0] != '1';
      need += s[i][m - 1] != '1';
    }
    for (int j = 1; j + 1 < m; j++) {
      need += s[0][j] != '1';
      need += s[n - 1][j] != '1';
    }
    int have = 0;
    for (int i = 1; i + 1 < n; i++) {
      for (int j = 1; j + 1 < m; j++) {
        have += s[i][j] == '1';
      }
    }
    if (need > have) {
      puts("-1");
    } else {
      printf("%d\n", need);
    }
  }
  return 0;
}