#include <bits/stdc++.h>

using namespace std;

long long mul(long long a, long long b, long long md) {
  return (long long) a * b % md;
}

long long power(long long x, long long e, long long md) {
  long long ret = 1, res = x;
  while (e) {
    if (e & 1) ret = mul(ret, res, md);
    res = mul(res, res, md);
    e >>= 1;
  }
  return ret;
}


int main() {
  long long n, k, a;
  int tc = 0;
  while (scanf("%lld %lld %lld", &n, &k, &a) && n + k + a > 0) {
    printf("Case %d:\n", ++tc);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      if (i > 0) putchar(' ');
      long long x; scanf("%lld", &x);
      long long ans = mul(a, power(k, n, x), x);
      printf("%lld", ans);
    }
    puts("");
  }
  return 0;
}