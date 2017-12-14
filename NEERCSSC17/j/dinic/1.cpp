#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

int n, m;
int a[N], b[N];
int deg[N];

template <typename T>
class flow_graph {
  public:
  int n;
  int s, t;
  struct edge {
    int to;
    T f;
    T c;
    int rev;
  };
  T flow;
  vector< vector<edge> > g;
  vector<int> d;
  vector<int> ptr;

  flow_graph(int n) : n(n), s(0), t(n - 1) {
    g.resize(n);
    d.resize(n);
    ptr.resize(n);
  }

  void add_edge(int from, int to, T fw_cap, T bw_cap = 0) {
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

  bool ex_path() {
    fill(d.begin(), d.end(), -1);
    d[0] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (edge &e : g[v]) {
        if (e.c - e.f > 0 && d[e.to] == -1) {
          d[e.to] = d[v] + 1;
          if (e.to == t) {
            return true;
          }
          q.push(e.to);
        }
      }
    }
    return false;
  }

  T dfs(int v = 0, T c = (int) 1e9) {
    if (v == t) return c;
    int &w = ptr[v];
    while (w >= 0) {
      edge &e = g[v][w];
      if (e.c - e.f > 0 && d[e.to] == d[v] + 1) {
        int ret = dfs(e.to, min(c, e.c - e.f));
        if (ret > 0) {
          e.f += ret;
          g[e.to][e.rev].f -= ret;
          return ret;
        }
      }
      w--;
    }
    return 0;
  }

  T max_flow() {
    while (ex_path()) {
      for (int i = 0; i < n; i++) {
        ptr[i] = (int) g[i].size() - 1;
      }
      T bf = 0;
      while (true) {
        T f = dfs();
        if (f == 0) break;
        bf += f;
      }
      if (bf == 0) break;
      flow += bf;
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
  flow_graph<int> graph(n + m + 2);
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
        printf("%d %d\n", e.to - m, (e.to - m) ^ a[i] ^ b[i]);
      }
    }
    if (!ok) {
      assert(0);
    }
  }
  return 0;
}