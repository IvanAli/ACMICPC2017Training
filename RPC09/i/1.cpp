#include <bits/stdc++.h>

using namespace std;

const int N = 50;
const long long inf = (long long) 1e18;

long long m;
int k;
long long dp[N + 5][2][N + 5];

long long solve(int i = N, bool ok = false, int c = 0) {
  if (c == k && ok) {
    return 0;
  }
  if (i < 0) {
    if (ok && c == k) return 0;
    return inf;
  }
  if (dp[i][ok][c] != -1) return dp[i][ok][c];
  long long ret = inf;
  if (m & (1ll << i)) {
    ret = min(ret, (1ll << i) + solve(i - 1, ok, c + 1));
  } else {
    ret = min(ret, solve(i - 1, ok, 0));
    ret = min(ret, (1ll << i) + solve(i - 1, true, c + 1));
  }
  return dp[i][ok][c] = ret;
}

bool ok() {
  int cnt = 0;
  for (int i = 50; i >= 0; i--) {
    if (m & (1ll << i)) cnt++;
    else cnt = 0;
    if (cnt == k) return true;
  }
  return false;
}

int main() {
  while (scanf("%lld %d", &m, &k) == 2) {
    memset(dp, -1, sizeof dp);
    long long ans = solve();
    if (ok()) printf("%lld\n", m);
    else printf("%lld\n", ans);
  }
  return 0;
}