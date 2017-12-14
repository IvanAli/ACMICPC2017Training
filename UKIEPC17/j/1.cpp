#include <bits/stdc++.h>

using namespace std;

double dp[10];

int main() {
  int n;
  scanf("%d", &n);
  dp[0] = 2;
  dp[1] = 1;
  for (int i = 1; i < 6; i++) dp[1 << i] = dp[1 << (i - 1)] / 2.;
  double ans = 0;
  for (int i = 0; i < n; i++) {
    int x; scanf("%d", &x);
    ans += dp[x];
  }
  printf("%.6lf\n", ans);  
  return 0;
}