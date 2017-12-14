#include <bits/stdc++.h>
using namespace std;

int T;
int n, k;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &k);
    long long ans = 0;
//    for (int i = 0; i < 2 * k + 1; i++) for (int j = 0; j < 2 * k + 1; j++) if (abs(i - j) <= k) ans++;
    for (int i = 0; i < 2 * k + 1; i++) {
      long long low = max(0, i - k);
      long long high = min(2 * k, i + k);
      ans += high - low + 1;
    }
    ans *= (long long) (n + 1 - 2ll * k);
/*    for (int i = 0; i < k; i++) for (int j = 0; j <= i + k; j++) {
      long long low = max(0, j - k);
      long long high = min(i + k, j + k);
      ans += 2 * (high - low + 1);
    }
*/
    printf("%lld\n", ans);
  }
  return 0;
}