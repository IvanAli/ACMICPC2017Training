#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int n;

int a[N];
long long lf_max[N], lf_min[N], rg_max[N], rg_min[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0, cur = 0, ans = 0, ok = false; i < n; i++) {
      int add = a[i];
      if (i % 2 == 1) add *= -1;
      if (ok) add *= -1;
      cur += add;
      if (cur < 0) {
        ok ^= true;
        cur = 0;
      }
      ans = max(ans, cur);
      lf_max[i] = ans;
    }
    for (int i = n - 1, cur = 0, ans = 0, ok = false; i >= 0; i--) {
      int add = a[i];
//      if (i % 2 == 1) add *= -1;
//      if (ok) add *= -1;
      cur += add;
      if (cur < 0) {
        ok ^= true;
        cur = 0;
      }
      ans = max(ans, cur);
      rg_max[i] = ans;
      cur *= -1;
    }
    for (int i = 0, cur = 0, ans = 0, ok = false; i < n; i++) {
      int add = -a[i];
      if (i % 2 == 1) add *= -1;
      if (ok) add *= -1;
      cur += add;
      if (cur < 0) {
        ok ^= true;
        cur = 0;
      }
      ans = max(ans, cur);
      lf_min[i] = -ans;
    }
    for (int i = n - 1, cur = 0, ans = 0, ok = false; i >= 0; i--) {
      int add = -a[i];
//      if (i % 2 == 1) add *= -1;
//      if (ok) add *= -1;
      cur += add;
      if (cur < 0) {
        ok ^= true;
        cur = 0;
      }
      ans = max(ans, cur);
      rg_min[i] = -ans;
      cur *= -1;
    }
    long long ans = 0;
    long long res;
    for (int i = 0; i + 1 < n; i++) {
      res = lf_max[i] - rg_min[i + 1];
      if (res < 0) res = -res;
      ans = max(ans, res);
      res = lf_min[i] - rg_max[i + 1];
      if (res < 0) res = -res;
      ans = max(ans, res);
    }
    printf("%lld\n", ans);
  }
  return 0;
}