#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

int n, m;
int a[N], b[N];
int deg[N];

class flow_graph {
  public:
  int n;
  int s, t;
  struct edge {
    int to, f, c, rev;
  };
  int flow;
  vector< vector<edge> > g;
  vector<int> d;
  vector<int> ptr;

  flow_graph(int n) : n(n), s(0), t(n - 1) {
    g.resize(n);
    d.resize(n);
    ptr.resize(n);
  }

  void add_edge(int from, int to, int fw_cap, int bw_cap = 0) {
    int to_size = (int) g[to].size();
    int from_size = (int) g[from].size();
    g[from].push_back({to, 0, fw_cap, to_size});
    g[to].push_back({from, 0, bw_cap, from_size});
  }
  
  void clear_flow() {
    flow = 0;
    for (int i = 0; i < n; i++) {
      for (edge &e : g[i]) e.f = 0;
    }
  }

  int bfs() {
    vector< pair<int, int> > from(n);
    for (int i = 0; i < n; i++) from[i] = make_pair(-1, -1);
    fill(d.begin(), d.end(), 0);
    queue<int> q;
    q.push(s);
    d[s] = 1;
    bool ok = false;
    while (!q.empty() && !ok) {
      int v = q.front(); q.pop();
      for (int i = 0; i < (int) g[v].size(); i++) {
        edge e = g[v][i];
        if (e.c - e.f > 0 && d[e.to] == 0) {
          d[e.to] = 1;
          from[e.to] = make_pair(v, i);
          if (e.to == t) {
            ok = true;
            break;
          }
          q.push(e.to);
        }
      }
    }
    int v = t;
    int ret = (int) 1e9;
    while (from[v].first > -1) {
      auto pr = from[v];
      edge e = g[pr.first][pr.second];
      ret = min(ret, e.c - e.f);
      v = pr.first;
    }
    if (ret == (int) 1e9) return 0;
    v = t;
    while (from[v].first > -1) {
      auto pr = from[v];
      edge &e = g[pr.first][pr.second];
      e.f += ret;
      g[v][e.rev].f -= ret;
      v = pr.first;
    }              
    return ret;
  }

  int max_flow() {
    while (true) {
      int f = bfs();
      if (f == 0) break;
      flow += f;
    }
    return flow;
  }

  bool ok(int mid) {
    clear_flow();
    return max_flow() == m;
  }
};

int main() {
  scanf("%d %d", &n, &m);
  flow_graph graph(n + m + 2);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", a + i, b + i);
    graph.add_edge(graph.s, i + 1, 1);
    graph.add_edge(i + 1, a[i] + m, 1);
    graph.add_edge(i + 1, b[i] + m, 1);
    deg[a[i] + m]++; deg[b[i] + m]++;
  }
  for (int i = 0; i < n; i++) {
    graph.add_edge(i + 1 + m, graph.t, 1);
  }
  int low = 0, high = m;
  while (low < high) {
    int mid = low + high >> 1;
    for (int i = 0; i < n; i++) {
      auto &e = graph.g[i + 1 + m].back();
      assert(e.to == graph.t);
      e.c = min(mid, deg[i + 1 + m]);
    }
    if (graph.ok(mid)) high = mid;
    else low = mid + 1;
  }
  for (int i = 0; i < n; i++) {
    auto &e = graph.g[i + 1 + m].back();
    assert(e.to == graph.t);
    e.c = min(low, deg[i + 1 + m]);
  }
  assert(graph.ok(low));
  printf("%d\n", low);
  for (int i = 0; i < m; i++) {
    bool ok = false;
    for (auto e : graph.g[i + 1]) {
      if (e.to >= m + 1 && e.f == 1) {
        ok = true;
        if (a[i] == e.to - m) printf("%d %d\n", e.to - m, b[i]);
        else printf("%d %d\n", e.to - m, a[i]);
      }
    }
    if (!ok) {
      assert(0);
    }
  }
  return 0;
}