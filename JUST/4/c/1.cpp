#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
const int N = 1234567;

pair<int, int> pr[N];
int ans[N];

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int a; scanf("%d", &a);
      pr[i] = make_pair(a, i);
    }
    sort(pr, pr + n);
    for (int i = 0, j = n - 1; i < n; i++) {
      while (j >= 0 && pr[i].first + pr[j].first >= mod || i == j) {
        j--;
      }
      int id = pr[i].second;
      if (j < 0) {
        if (i == n - 1) ans[id] = (pr[i].first + pr[n - 2].first) % mod;
        else ans[id] = (pr[i].first + pr[n - 1].first) % mod;
      } else ans[id] = (pr[i].first + pr[j].first) % mod;
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", ans[i]);
    }
    puts("");
  }
  return 0;
}