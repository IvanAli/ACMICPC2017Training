#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int T;
int n;
int x[N];
int h[N];
int lef[N], rig[N];
int lg[N];
int dp[N][25];
long long xx[N];
int width;

int rmq(int x, int y) {
  int l_len = lg[y - x + 1];
  if (x > y) return -1;
//  if (x + 1 == y || x == y) return -1;
  int a = dp[x][l_len];
  int b = dp[y - (1 << l_len) + 1][l_len];
  if (h[a] > h[b]) return a;   
  return b;
}

int main() {
  scanf("%d", &T);
  for (int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
  while (T--) {
    scanf("%d %d", &width, &n);
    for (int i = 0; i < n; i++) scanf("%d", x + i + 1);
    for (int i = 0; i < n + 1; i++) scanf("%d", h + i);
    lef[0] = -1;
    rig[n] = -1;
    for (int i = 1; i <= n; i++) {
      xx[i] = x[i];
      if (i > 0) xx[i] += xx[i - 1];
    }
    for (int i = 1; i <= n; i++) {
      lef[i] = i - 1;
      while (lef[i] > -1 && h[lef[i]] < h[i]) lef[i] = lef[lef[i]];
    }
    for (int i = n - 1; i >= 0; i--) {
      rig[i] = i + 1;
      while (rig[i] > -1 && h[rig[i]] <= h[i]) rig[i] = rig[rig[i]];
    }
    for (int i = 0; i < n; i++) dp[i][0] = i;
    for (int j = 1; 1 << j <= n; j++) for (int i = 0; i + (1 << j) - 1 < n; i++) {
      int w_lef = dp[i][j - 1];
      int w_rig = dp[i + (1 << (j - 1))][j - 1];
      if (h[w_lef] >= h[w_rig]) dp[i][j] = w_lef;
      else dp[i][j] = w_rig;
    }
    long long ans = 0;
    for (int i = 0; i <= n; i++) {
//      fprintf(stderr, "i: %d lef: %d rig: %d\n", i, lef[i], rig[i]);
      if (lef[i] > -1) {
        int w_max = rmq(lef[i] + 1, i - 1);
        long long sub = 0;
        long long len = xx[i] - xx[lef[i]];
        if (w_max > -1) sub = (long long) len * width * h[w_max];
        long long add = (long long) len * width * h[i] - sub;
//        fprintf(stderr, "add lef: %lld len: %lld\n", add, len);
        ans += add;
      }
      if (rig[i] > -1) {
        int w_max = rmq(i + 1, rig[i] - 1);
        long long sub = 0;
        long long len = xx[rig[i]] - xx[i];
        if (w_max > -1) sub = (long long) len * width * h[w_max];
        long long add = (long long) len * width * h[i] - sub;
//        fprintf(stderr, "add rig: %lld len: %lld\n", add, len);
        ans += add;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}                                        