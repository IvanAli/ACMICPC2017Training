#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const int mod = (int) 1e9 + 7;

int T;

int a, b;
int fact[N];
int ifact[N];

int mul(int a, int b) {
  return (long long) a * b % mod;
}

int power(int x, int e) {
  int ret = 1;
  int res = x;
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

int c(int n, int k) {
  int ret = fact[n];
  ret = mul(ret, ifact[n - k]);
  ret = mul(ret, ifact[k]);
  return ret;
}

int main() {
  scanf("%d", &T);
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    ifact[i] = mul(ifact[i - 1], inv(i));
  }
  while (T--) {
    scanf("%d %d", &a, &b);
    printf("%d\n", mul(2, c(a - 1, b)));
  }
  return 0;
}