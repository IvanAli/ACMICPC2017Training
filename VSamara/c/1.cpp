#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
const int N = 222;

int fact[N];
int ifact[N];

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


int c(int n, int k) {
  if (n < k) return 0;
  int ret = fact[n];
  ret = mul(ret, ifact[n - k]);
  ret = mul(ret, ifact[k]);
  return ret;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int n, m;
  fact[0] = 1;
  ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(i, fact[i - 1]);
    ifact[i] = mul(inv(i), ifact[i - 1]);
  }
  scanf("%d %d", &n, &m);
  int ans = c(m, n);
  printf("%d\n", ans);
  return 0;
}