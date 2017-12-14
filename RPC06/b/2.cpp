#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    long long ans = 0;
    long long cnt = 0;
    for (int i = 0; i < 2 * k + 1; i++) {
      for (int j = 0; j < 2 * k + 1; j++) {
        long long cur = k - max(0, i + k - j);
        ans += 2 * cur + 1;
      }
      cnt += k + 1 - max(0, i + k - 2 * k);
      cnt += k - max(0, -(i - k));
    }
    fprintf(stderr, "cnt: %lld\n", cnt);
    fprintf(stderr, "times: %d\n", n + 1 - 2 * k);
    ans += cnt * (long long) (max(0ll, (long long) n + 1 - 2ll * k));
    printf("%lld\n", ans);
  }
  return 0;
}