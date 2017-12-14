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
    long long cur;
    for (int i = 0; i < 2 * k + 1; i++) {
      fprintf(stderr, "i: %d\n", i);
      cur = k + 1 - max(0, i + k - 2 * k);
      cnt += cur; cerr << "cur: " << cur << endl;
      ans += (cur * cur + cur) / 2;
      cur = k - max(0, -(i - k));
      cnt += cur; cerr << "cur: " << cur << endl;
      ans += (cur * cur + cur) / 2;
    }
    fprintf(stderr, "cnt: %lld\n", cnt);
    fprintf(stderr, "ans: %lld\n", ans);
    fprintf(stderr, "n: %d\n", n);
    ans += cnt * (long long) (max(0ll, (long long) n + 1 - 2ll * k));
    printf("%lld\n", ans - 1);
  }
  return 0;
}