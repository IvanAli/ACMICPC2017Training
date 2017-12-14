#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

template <typename T>
class flow_graph {
  public:
  struct edge {
    int to;
    T f;
    T c;
    int rev;
  };

  int n, s, t;
  T flow;
  vector< vector<edge> > g;
  vector<int> ptr, d;

  flow_graph(int n, int s, int t) : n(n), s(s), t(t) {
    g.resize(n);
    ptr.resize(n);
    d.resize(n);
    flow = 0;
  }

  void add(int from, int to, T fw_cap, int bw_cap = 0) {
    int from_size = g[from].size();
    int to_size = g[to].size();
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
      for (int i = 0; i < n; i++) ptr[i] = (int) g[i].size() - 1;
      T big_add = 0;
      while (true) {
        T add = dfs(s, numeric_limits<int>::max());
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
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    flow_graph<int> g(1002, 0, 1001);
    for (int i = 0; i < n; i++) {
      int x, y, z; scanf("%d %d %d", &x, &y, &z);
      g.add(0, x * 100 + y * 10 + z + 1, numeric_limits<int>::max());
    }
    for (int x = 0; x < 10; x++) for (int y = 0; y < 10; y++) for (int z = 0; z < 10; z++) {
      for (int k = 0; k < 6; k++) {
        int xk = x + dx[k];
        int yk = y + dy[k];
        int zk = z + dz[k];
        if (xk < 0 || xk >= 10 || yk < 0 || yk >= 10 || zk < 0 || zk >= 10) {
          g.add(x * 100 + y * 10 + z + 1, g.t, 1);
          continue;
        }
        g.add(x * 100 + y * 10 + z + 1, xk * 100 + yk * 10 + zk + 1, 1);
      }
    }
    int ans = g.max_flow();
    printf("%d\n", ans);
  }
  return 0;
}