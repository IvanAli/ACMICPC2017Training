#include <bits/stdc++.h>

using namespace std;

const int N = 2345;

int n, c, t1, t2;
int dp[N];
int f[N];

int main() {
  scanf("%d %d %d %d", &n, &c, &t1, &t2);
  for (int i = 0; i < n; i++) scanf("%d", f + i);
  for (int i = 0; i < n; i++) dp[i + 1] = 1 << 30;
  for (int i = 0, j = 0, k = 0, d_t1 = 0, d_t2 = 0, l_t1 = f[0], l_t2 = f[0], add_t1 = 0, add_t2 = 0; i < n; i++) {
    while (j < n && d_t1 <= t1) {
      add_t1 = f[j] - l_t1;
      if (d_t1 + add_t1 > t1) break;
      d_t1 += add_t1;
      l_t1 = f[j];
      j++;
    }
    while (k < n && d_t2 <= t2) {
      add_t2 = f[k] - l_t2;
      if (d_t2 + add_t2 > t2) break;
      d_t2 += add_t2;
      l_t2 = f[k];
      k++;
    }
    dp[j] = min(dp[j], dp[i] + t1);
    dp[k] = min(dp[k], dp[i] + t2);
    d_t1 -= (f[i + 1] - f[i]);
    d_t2 -= (f[i + 1] - f[i]);
  }
  printf("%d\n", dp[n]);
  return 0;
}