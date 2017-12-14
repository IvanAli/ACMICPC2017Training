#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int T;
int x, a, d, m;
int xp[N], ap[N], dp[N];
set<tuple<int, int, int>> ma;
char name[N << 2];

int main() {
  scanf("%d", &T);
  while (T--) {
    ma.clear();
    int ok = 0;
    scanf("%d %d %d %d", &x, &a, &d, &m);
    for (int i = 0; i < m; i++) scanf("%s %d %d %d", name, xp + i, ap + i, dp + i);
    for (int mask = 0; mask < 1 << (m / 2); mask++) {
      int xx = 0, aa = 0, dd = 0;
      for (int i = 0; i < m / 2; i++) if (mask & (1 << i)) {
        xx += xp[i];
        aa += ap[i];
        dd += dp[i];
        if (xx > x) continue;
        if (aa > a) continue;
        if (dd > d) continue;
      }
      if (xx == x && aa == a && dd == d) {
        ok = 1;
        break;
      }
      if (ok) break;
      ma.insert(make_tuple(xx, aa, dd));
    }
    for (int mask = 0; mask < 1 << ((m + 1) / 2); mask++) {
      int xx = 0, aa = 0, dd = 0;
      for (int i = 0; i < (m + 1) / 2; i++) if (mask & (1 << i)) {
        xx += xp[i + m / 2];
        aa += ap[i + m / 2];
        dd += dp[i + m / 2];
        if (xx > x) continue;
        if (aa > a) continue;
        if (dd > d) continue;
      }
      if (ma.count(make_tuple(x - xx, a - aa, d - dd))) {
        ok = 1;
        break;
      }
      if (xx == x && aa == a && dd == d) {
        ok = 1;
        break;
      }
      if (ok) break;
    }
    if (ok) printf("POSSIBLE\n");
    else printf("IMPOSSIBLE\n");
  }     
  return 0;
}