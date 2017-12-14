#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int n, s;
int ans[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) ans[i] = 0;
    if (s <= 9 * n) {
      if (n % 2 == 0 && s % 2 == 1) {
        puts("-1");
        continue;
      }
      for (int i = 0; i < n / 2; i++) {
        for (int d = 9; d >= 0; d--) {
          if (d + d <= s) {
            ans[i] = d;
            s -= (d + d);
            break;
          }
        }
      }
      assert(s < 10);
      if (n % 2 == 1) ans[n / 2] = s;
      for (int i = 0; i < n / 2; i++) printf("%d", ans[i]);
      if (n % 2 == 1) printf("%d", ans[n / 2]);
      for (int i = n / 2 - 1; i >= 0; i--) printf("%d", ans[i]);
      puts("");
    } else puts("-1");
  }
  return 0;
}