#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

char s[N];

int dist(int a, int b) {
  int ret = (int) 1e9;
  if (a > b) swap(a, b);
  if (a <= b) ret = min(ret, b - a);
  ret = min(ret, a + 26 - b);
  return ret;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, p;
    scanf("%d %d", &n, &p);
    scanf("%s", s);
    p--;
    int lf = n, rg = -1;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        if (p < n / 2) {
          if (i <= p) lf = min(lf, i);
          if (n - i - 1 <= p) lf = min(lf, n - i - 1);
          if (i >= p && i < n / 2) rg = max(rg, i);
          if (n - i - 1 >= p && n - i - 1 < n / 2) rg = max(rg, n - i - 1);
        } else {
          if (i <= p && i >= (n + 1) / 2) lf = min(lf, i);
          if (n - i - 1 <= p && n - i - 1 >= (n + 1) / 2) lf = min(lf, n - i - 1);
          if (i >= p) rg = max(rg, i);
          if (n - i - 1 >= p) rg = max(rg, n - i - 1);
        }
      }
      ans += dist(s[i] - 'a', s[n - i - 1] - 'a');
    }
    if (lf == n) lf = p;
    if (rg == -1) rg = p;
    ans += 2 * min(p - lf, rg - p) + max(p - lf, rg - p);
    printf("%d\n", ans);
  }
  return 0;
}