#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    long long ans = 0;
    for (int i = 0; i < 31; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++) {
        bool z = a[j] & (1 << i);
        if (z == 0) {
          if (cnt > 0) {
            long long t = (long long) cnt * (cnt + 1) / 2;
            ans += t * (1 << i);
          }
          cnt = 0;
        } else {
          cnt++;
        }
      }
      if (cnt > 0) {
        long long t = (long long) cnt * (cnt + 1) / 2;
        ans += t * (1 << i);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}