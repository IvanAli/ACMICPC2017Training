#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int mod = 1000000;

long long n, m, l;

int dp[N][N][2];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int main() {
  scanf("%lld %lld %lld", &n, &m, &l);
  dp[0][0][0] = 1;
  for (int i = 0; i < n / 5; i++) {
    for (int j = 0; j < l; j++) {
      for (int k = 0; k < l; k++) {
        dp[i + 2][j][1] = add(dp[i + 2][j][1], dp[i][k][1]);
      }
      for (int k = 0; k < m; k++) {
        dp[i + 2][j][1] = add(dp[i + 2][j][1], dp[i][k][0]);
      }
    }
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < l; k++) {
        dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][k][1]);
      }
      for (int k = 0; k < m; k++) {
        dp[i + 1][j][0] = add(dp[i + 1][j][0], dp[i][k][0]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < l; i++) {
    ans = add(ans, dp[n / 5][i][1]);
  }
  for (int i = 0; i < m; i++) {
    ans = add(ans, dp[n / 5][i][0]);
  }
  printf("%d\n", ans);
  return 0;
}