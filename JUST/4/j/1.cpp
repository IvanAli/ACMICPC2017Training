#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int mod = (int) 1e9 + 7;

int a[N];
int dp[N];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    dp[0] = 0;
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      dp[i + 1] = add(a[i], mul(a[i], sum));
      sum = add(dp[i + 1], sum);
      ans = add(ans, dp[i + 1]);
    }
    printf("%d\n", ans);
  }
  return 0;
}