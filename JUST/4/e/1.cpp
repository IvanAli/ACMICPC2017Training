#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
const int N = 20;

int n, x;
map<int, int> dp;
int f[N][N];

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int power(int x, int e) {
  int ret = 1, res = x;
  while (e) {
    if (e & 1) ret = mul(ret, res);
    res = mul(res, res);
    e >>= 1;
  }
  return ret;
}

int inv(int x) {
  return power(x, mod - 2);
}

void go(int i = 0, int m = 1) {
  if (i == n / 2) {
    dp[m]++;
    return;
  }
  for (int j = 0; j < 6; j++) {
    go(i + 1, mul(m, f[i][j]));
  }
}

long long solve(int i = n / 2, int m = 1) {
  if (i == n) {
    return dp[mul(x, inv(m))];
  }
  long long ret = 0;
  for (int j = 0; j < 6; j++) ret += solve(i + 1, mul(m, f[i][j]));
  return ret;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    dp.clear();
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) for (int j = 0; j < 6; j++) scanf("%d", f[i] + j);
    go();
    long long ans = solve();
    printf("%lld\n", ans);
  }
  return 0;
}