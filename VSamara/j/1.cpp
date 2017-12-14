#include <bits/stdc++.h>

using namespace std;

const int N = 1111;

int n, m;
vector< tuple<int, int, int> > g[N];
int d[N];
int T;

pair<bool, int> ok(int x) {
  priority_queue<int, vector< pair<int, int> >, greater< pair<int, int> > > pq;
  for (int i = 0; i < n; i++) d[i] = (int) 2e9 + 1;
  d[0] = 0;
  pq.emplace(d[0], 0);
  while (!pq.empty()) {
    auto ft = pq.top(); pq.pop();
    int dd = ft.first, v = ft.second;
    if (dd > d[v]) continue;
    for (auto e : g[v]) {
      int to, t, s; tie(to, t, s) = e;
      if (s > x) continue;
      if (d[v] + t < d[to]) {
        d[to] = d[v] + t;
        pq.emplace(d[to], to);
      }
    }
  }
  return make_pair(d[n - 1] <= T, d[n - 1]);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
    a--, b--;
    g[a].emplace_back(b, c, d);
    g[b].emplace_back(a, c, d);
  }
  scanf("%d", &T);
  int low = 0, high = (int) 1e6, mid;
  while (low < high) {
    mid = low + high >> 1;
    pair<bool, int> eval = ok(mid);
    if (eval.first) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  auto eval = ok(low);
  if (eval.first) {
    puts("YES");
    printf("%d %d\n", low, eval.second);
  } else {
    puts("NO");
  }
  return 0;
}