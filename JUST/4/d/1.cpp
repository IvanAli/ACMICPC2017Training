#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int have[N][26];
char s[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, q; scanf("%d %d", &n, &q);
    scanf("%s", s);
    memset(have, 0, sizeof have);
    for (int i = 0; i < n; i++) {
      have[i][s[i] - 'a']++;
      if (i > 0) for (int j = 0; j < 26; j++) have[i][j] += have[i - 1][j];
    }
    while (q--) {
      int l, r; char c; scanf("%d %d %c", &l, &r, &c); l--, r--;
      int ll = l % n;
      int rr = r % n;
      int t = (r - ((rr + 1) % n) - (l + (ll > 0 ? n - ll : 0)) + 1) / n;
      int ans = t * have[n - 1][c - 'a'];
      if (rr < n - 1) ans += have[rr][c - 'a'];
      if (ll > 0) ans += have[n - 1][c - 'a'] - have[ll - 1][c - 'a'];
      printf("%d\n", ans);
    }
  }
  return 0;
}