#include <bits/stdc++.h>
using namespace std;

int n, d;
int T;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &d);
    long long ans = 0;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) if (abs(i - j) <= d && abs(i - k) <= d && abs(j - k) <= d) ans++;
    printf("%lld\n", ans);
  }
  return 0;
}