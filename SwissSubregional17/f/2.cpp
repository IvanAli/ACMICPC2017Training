#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 5005;
const int Y = 377;

long long dp[Y][M][2];
int pb[M], pe[M];
int st[M], fin[M], id[M], cost[M];
int pr[M];

struct seg {
  int id, b, e, c;

  seg() {}

  seg(int id, int b, int e, int c) : id(id), b(b), e(e), c(c) {}
}; 

seg segs_b[N], segs_e[N];

int main() {
  int y, n, s;
  scanf("%d %d %d", &y, &n, &s);
  int h, m;
  scanf("%d %d", &h, &m);
  for (int i = 0; i < m; i++) {
    pb[i] = i;
    pe[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int w, b, e, c;
    scanf("%d %d %d %d", &w, &b, &e, &c);
    id[i] = w;
    st[i] = b;
    fin[i] = e;
    cost[i] = c;
   // segs_b[i] = seg(id, b, e, c);
   // segs_e[i] = seg(id, b, e, c);
  }
  sort(pb, pb + m, [&](const int i, const int j) {
    if (st[i] == st[j]) return fin[i] < fin[j];
    return st[i] < st[j];
  });
  sort(pe, pe + m, [&](const int i, const int j) {
    if (fin[i] == fin[j]) return st[i] < st[j];
    return fin[i] < fin[j];
  });
  /*
  sort(segs_a, segs_a + m, [&](const seg &a, const seg &b) {
    if (a.b == b.b) return a.e < b.e;
    return a.b < b.b;
  });
  sort(segs_b, segs_b + m, [&](const seg &a, const seg &b) {
    if (a.e == b.e) return a.b < b.b;
    return a.e < b.e;
  });
  */
  memset(pr, -1, sizeof pr);
  for (int i = 0, j = 0; i < m; i++) {
    while (j < m && fin[pe[j]] <= st[pb[i]]) j++;
    if (j - 1 >= 0 && id[pe[j - 1]] != id[pb[i]]) {
      pr[i] = j - 1;
    } else {
      if (j == m) j--;
      while (j >= 0 && id[pe[j]] == id[pb[i]]) j--;
      if (j >= 0) pr[i] = j;
      if (j < 0) j = 0;
    }
  }
  for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = (long long) 1e18;
  for (int k = 0; k < 2; k++) dp[0][0][k] = 0;
  for (int i = 1; i <= max(n, s); i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (k == 0) {
          int days = fin[pb[j]] - st[pb[j]];
          dp[i][j][k] = min(dp[i][j][k], cost[pb[i]] + (i - days >= 0 ? dp[i - days][pr[j]][k] : 0));
        } else {
          dp[i][j][k] = min(dp[i][j][k], cost[pb[i]] + (i > 0 && j > 0 ? dp[i - 1][j - 1][k] : 0));
        }
      }
    }
  }
  long long ans = (long long) 1e18;
  bool what = false;
  for (int i = n; i < N; i++) {
    ans = min(ans, dp[i][m][0]);
  }
  for (int i = s; i < N; i++) {
    if (dp[i][m][1] < ans) {
      ans = min(ans, dp[i][m][1]);
      what = true;
    }
  }
  if (ans >= (long long) 1e18) {
    puts("IMPOSSIBLE");
  } else {
    if (what) puts("STAYS");
    else puts("NIGHTS");
    printf("%lld\n", ans);
  }
  return 0;
}