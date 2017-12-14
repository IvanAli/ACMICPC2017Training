#include <bits/stdc++.h>

using namespace std;

const int N = 2345;

int T;
int n;
int a[N];

long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      long long cur_lcm = 1;
      long long cur_sum = 0;
      for (int j = i; j < n; j++) {
        cur_lcm = lcm(cur_lcm, a[j]);
        cur_sum += a[j];
        if (cur_sum % cur_lcm == 0) ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}