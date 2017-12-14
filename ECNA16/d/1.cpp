#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n, m;
int cost[N][N];
char s[N], a[N], b[N];
map<string, int> ma;
int parent[N];
vector< pair<int, int> > g[N];
pair<int, int> d[N];

int main() {
  scanf("%d %d", &n, &m);
  int sz = 0;
  int eng = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    ma[string(s)] = sz;
    if (strcmp("English", s) == 0) eng = sz;
    sz++;
  }
  if (eng == -1) {
    ma["English"] = sz;
    eng = sz++;
  }
  for (int i = 0; i < m; i++) {
    int c; scanf("%s %s %d", a, b, &c);
    int wa = ma[string(a)];
    int wb = ma[string(b)];
    g[wa].emplace_back(wb, c);
    g[wb].emplace_back(wa, c);
    cost[wa][wb] = c;
    cost[wb][wa] = c;
  }
  for (int i = 0; i < sz; i++) d[i] = make_pair((int) 1e9, (int) 1e9);
  d[eng] = make_pair(0, 0);
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
  pq.emplace(d[eng].first, eng);
  while (!pq.empty()) {
    pair<int, int> ft = pq.top(); pq.pop();
    int v = ft.second, dd = ft.first;
    if (dd > d[v].first) continue;
    for (auto e : g[v]) {
      if (d[v].first + 1 < d[e.first].first) {
        d[e.first].first = d[v].first + 1;
        d[e.first].second = d[v].second + e.second;
        parent[e.first] = v;
        pq.emplace(d[e.first].first, e.first);
      } else if (d[v].first + 1 == d[e.first].first && d[v].second + e.second < d[e.first].second) {
        d[e.first].second = d[v].second + e.second;
        parent[e.first] = v;
        pq.emplace(d[e.first].first, e.first);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (d[i].first >= (int) 1e9) {
      puts("Impossible");
      return 0;
    }
  }
  set< pair<int, int> > st;
  for (int i = 0; i < n; i++) {
    int cur = i;
    while (cur != eng) {
      int pr = parent[cur];
      st.insert(make_pair(min(pr, cur), max(pr, cur)));
      cur = pr;
    }
  }
  long long ans = 0;
  for (auto it : st) {
    ans += cost[it.first][it.second];
  }
  printf("%lld\n", ans);
  return 0;
}