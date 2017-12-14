#include <bits/stdc++.h>

using namespace std;

const int N = 555;

int cat_cap[N];
int belongs[N];

template <typename T>
class flow_graph {
  public:
  int n, s, t;
  T flow;
  struct edge {
    int to;
    T f;
    T c;
    int rev;
  };
  vector<edge> g[N];
  vector<int> ptr;
  vector<int> d;

  flow_graph(int n, int s, int t) : n(n), s(s), t(t) {
    ptr.resize(n);
    d.resize(n);
    flow = 0;
  }

  void add(int from, int to, T fw_cap, T bw_cap = 0) {
    int from_size = g[from].size();
    int to_size = g[to].size();
    g[from].push_back({to, 0, fw_cap, to_size});
    g[to].push_back({from, 0, bw_cap, from_size});
  }

  bool ex_path() {
    queue<int> q;
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (edge &e : g[v]) {
        if (e.c - e.f > 0 && d[e.to] == -1) {
          d[e.to] = d[v] + 1;
          if (e.to == t) return true;
          q.push(e.to);
        }
      }
    }
    return false;
  }

  T dfs(int v, T w) {
    if (v == t) return w;
    int &j = ptr[v];
    while (j >= 0) {
      edge &e = g[v][j];
      if (e.c - e.f > 0 && d[e.to] == d[v] + 1) {
        T res = dfs(e.to, min(w, e.c - e.f));
        if (res > 0) {
          e.f += res;
          g[e.to][e.rev].f -= res;
          return res;
        }
      }
      j--;
    }
    return 0;
  }

  T max_flow() {
    while (ex_path()) {
      for (int i = 0; i < n; i++) ptr[i] = (int) g[i].size() - 1;
      T big_add = 0;
      while (true) {
        T add = dfs(s, numeric_limits<T>::max());
        if (add == 0) break;
        big_add += add;
      }
      if (big_add == 0) break;
      flow += big_add;
    }                 
    return flow;
  }
};

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);
  flow_graph<int> g(n + m + p + 2, 0, n + m + p + 1);
  for (int i = 0; i < n; i++) {
    g.add(g.s, i + 1, 1);
  }
  for (int i = 0; i < n; i++) {
    int k; scanf("%d", &k);
    while (k--) {
      int x; scanf("%d", &x);
      x--;
      g.add(i + 1, n + x + 1, 1);
    }
  }
  for (int i = 0; i < m; i++) belongs[i] = -1;
  for (int i = 0; i < p + 1; i++) cat_cap[i] = (int) 1e9;
  for (int i = 0; i < p; i++) {
    int k; scanf("%d", &k);
    while (k--) {
      int x; scanf("%d", &x);
      x--;
      belongs[x] = i;
      g.add(n + x + 1, n + m + i + 1, 1);
    }
    int r; scanf("%d", &r);
    cat_cap[i] = r;
  }
  for (int i = 0; i < m; i++) {
    if (belongs[i] == -1) {
      g.add(n + i + 1, n + m + p + 1, 1);
      belongs[i] = p;
    }
  }
  for (int i = 0; i < p + 1; i++) {
    g.add(n + m + i + 1, g.t, cat_cap[i]);
  }
  int ans = g.max_flow();
  printf("%d\n", ans);
  return 0;
}