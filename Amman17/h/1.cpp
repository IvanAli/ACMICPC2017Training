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
    memset(ans, 0, sizeof ans);
    if (s <= 9 * n) {
      if (n % 2 == 0 && s % 2 == 1) {
        puts("-1");
        continue;
      }
      if (n % 2 == 0) {
        int t = s / 18;
        int m = s % 18;
        for (int i = 0; i < n / 2; i++) {
          if (t > 0) {
            ans[i] = 9;
            t--;
          } else {
            if (m > 0) ans[i] = m / 2;
            else ans[i] = 0;
            m = 0;
          }
        }
        for (int i = 0; i < n / 2; i++) printf("%d", ans[i]);
        for (int i = n / 2 - 1; i >= 0; i--) printf("%d", ans[i]);
        puts("");
      } else {
        if (9 * n == s) {
          for (int i = 0; i < n; i++) printf("%d", 9);
          puts("");
        } else {
          int t = s / 18;
          int m = s % 18;
          ans[n / 2] = 0;
          for (int i = 0; i < n; i++) {
            if (t > 0) {
              ans[i] = 9;
              t--;
            } else {
              if (m > 0) {
                if (i == n / 2) {
                  ans[i] = m;
                } else {
                  ans[i] = m / 2;
                  ans[n / 2] = n % 2;
                }
                m = 0;
              } else ans[i] = 0;
              m = 0;
            }
          }
          for (int i = 0; i < n / 2; i++) printf("%d", ans[i]);
          printf("%d", ans[n / 2]);
          for (int i = n / 2 - 1; i >= 0; i--) printf("%d", ans[i]);
          puts("");
        }
      }
    } else puts("-1");
  }
  return 0;
}