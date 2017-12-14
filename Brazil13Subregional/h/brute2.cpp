#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int mod = 1000000;

long long n, m, l;

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
  scanf("%lld %lld %lld", &n, &m, &l);
  dp[0] = 1;
  for (int i = 0; i < n / 5; i++) {
    dp[i + 1] = add(dp[i + 1], mul(dp[i], m));
    dp[i + 2] = add(dp[i + 2], mul(dp[i], l));
  }
  int ans = dp[n / 5];
  printf("%d\n", ans);
  return 0;
}