#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, m;
vector< pair<int, int> > g[N];
set<int> d[N];

bool ok(int x) {
  queue< pair<int, int> > q;
  q.emplace(0, 0);
  for (int i = 0; i < n; i++) d[i].clear();
  d[0].insert(0);
  while (!q.empty()) {
    pair<int, int> ft = q.front(); q.pop();
    int v = ft.first, cnt = ft.second;
    for (auto e : g[v]) {
      int to = e.first;
      int w = e.second;
      if (w > x) {
        if (!d[to].count(cnt) && !d[to].count(cnt + 1) && (cnt > 0 ? !d[to].count(cnt - 1) : true) && cnt + 1 <= 1) {
          d[to].insert(cnt + 1);
          q.emplace(to, cnt + 1);
        }
      } else {
        if (!d[to].count(cnt)) {
          d[to].insert(cnt);
          q.emplace(to, cnt);
        }
      }
    }
  }
  return d[n - 1].count(0) + d[n - 1].count(1);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  int low = 0, high = (int) 1e9, mid;
  while (low < high) {
    mid = low + high >> 1;
    if (ok(mid)) high = mid;
    else low = mid + 1;
  }
  if (ok(low)) {
    printf("%d\n", low);
  } else {
    puts("-1");
  }
  return 0;
}