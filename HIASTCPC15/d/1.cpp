#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int mod = (int) 1e9 + 7;

int fact[N], ifact[N];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int c(int n, int k) {
  if (n < k) return 0;
  int ret = fact[n];
  ret = mul(ret, ifact[n - k]);
  ret = mul(ret, ifact[k]);
  return ret;
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

int main() {
  int T;
  scanf("%d", &T);
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(i, fact[i - 1]);
    ifact[i] = mul(inv(i), ifact[i - 1]);
  }
  while (T--) {
    int n, m, k, d;
    scanf("%d %d %d %d", &n, &m, &k, &d);
    int r = 0;
    for (int i = 0; i < n; i++) { 
      int foo; scanf("%d", &foo);
      if (foo >= d) r++;
    }
    int ans = 0;
    for (int i = 0; i <= m - k; i++) {
      ans = add(ans, mul(c(r, k + i), c(n - r, m - (k + i))));
    }
    printf("%d\n", ans);
  }
  return 0;
}