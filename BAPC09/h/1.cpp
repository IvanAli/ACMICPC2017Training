#include <bits/stdc++.h>

using namespace std;

template <typename T>
class flow_graph {
  public:
  struct edge {
    int to;
    T f;
    T c;
    int rev;
  };

  int n;
  int s, t;
  vector<vector<edge> > g;
  vector<int> d;
  vector<int> ptr;
  T flow;

  flow_graph(int n, int s, int t) : n(n), s(s), t(t) {
    g.resize(n);
    d.resize(n);
    ptr.resize(n);
    flow = 0;
  }

  void add(int from, int to, T fw_cap, T bw_cap = 0) {
    int from_size = (int) g[from].size();
    int to_size = (int) g[to].size();
    g[from].push_back({to, 0, fw_cap, to_size});
    g[to].push_back({from, 0, bw_cap, from_size});
  }

  bool ex_path() {
    fill(d.begin(), d.end(), -1);
    d[s] = 0;
    queue<int> q;
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

  T dfs(int v, int w) {
    if (v == t) return w;
    int &j = ptr[v];
    while (j >= 0) {
      edge &e = g[v][j];
      if (e.c - e.f > 0 && d[e.to] == d[v] + 1) {
        T ret = dfs(e.to, min(w, e.c - e.f));
        if (ret > 0) {
          e.f += ret;
          g[e.to][e.rev].f -= ret;
          return ret;
        }
      }
      j--;
    }
    return 0;
  }

  T max_flow() {
    while (ex_path()) {
      for (int i = 0; i < n; i++) {
        ptr[i] = (int) g[i].size() - 1;
      }
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
  int T; scanf("%d", &T);
  while (T--) {
    int n, m; scanf("%d %d", &n, &m);
    int xs, ys; scanf("%d %d", &xs, &ys); xs++, ys++;
    int xt, yt; scanf("%d %d", &xt, &yt); xt++, yt++;
    flow_graph<int> g((n + 1) * m + 2, 0, (n + 1) * m + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j + 1 <= m; j++) {
        int a; scanf("%d", &a);
        if (a > 0) g.add(i * m + j, i * m + j + 1, a + 1, a + 1);
      }
    }
    for (int i = 1; i + 1 <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int a; scanf("%d", &a);
        if (a > 0) g.add(i * m + j, (i + 1) * m + j, a + 1, a + 1);
      }
    }
    g.add(g.s, xs * m + ys, 1234567);
    g.add(xt * m + yt, g.t, 1234567);
    int ans = g.max_flow();
    printf("%d\n", ans * 1000); 
  }
  return 0;
}