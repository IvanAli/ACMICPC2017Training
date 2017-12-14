#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

const int N = 567;

int n, k;
int grid[N][N];
int a[4];
map<long long, vector<int> > ma;

long long go() {
  long long ret = 0;
  for (int i = 0; i < 4; i++) {
    long long power = 1;
    long long cur = 0;
    for (int j = 0; j < 4; j++) {
      int it = (i + j) % 4;
      cur += (long long) a[it] * power;
      power *= 101;
    }
    ret = max(ret, cur);
  }
  return ret;
}

int main() {
  while (scanf("%d %d", &n, &k) && n + k > 0) {
    ma.clear();
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%d", a + j);
      }
      int p; scanf("%d", &p);
      swap(a[2], a[3]);
      long long h = go();
      ma[h].push_back(p);
    }
    for (auto &it : ma) {
      sort(it.second.begin(), it.second.end());
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", grid[i] + j);
    long long ans = 0;
    bool ok = true;
    for (int i = 0; i + 1 < n && ok; i += 2) for (int j = 0; j + 1 < n && ok; j += 2) {
      a[0] = grid[i][j];
      a[1] = grid[i][j + 1];
      a[2] = grid[i + 1][j + 1];
      a[3] = grid[i + 1][j];
      long long h = go();
      if (!ma.count(h)) {
        ok = false;
        break;
      } else if (ma[h].empty()) {
        ok = false;
        break;
      } else {
        int back = ma[h].back();
        ma[h].pop_back();
        ans += back;
      }
    }
    if (ok) printf("%lld\n", ans);
    else puts("-1");
  }
  return 0;
}
