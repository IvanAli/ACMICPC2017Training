#include <bits/stdc++.h>

using namespace std;

const int N = 123;
const int M = 12345;

int n, m;
int floyd[N][N];
int ea[M], eb[M];
int cost[M];

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
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) floyd[i][j] = (int) 1e9;
  for (int i = 0; i < n; i++) floyd[i][i] = 0;
  flow_graph<int> g(2 * (n - 1) + 2, 0, 2 * (n - 1) + 1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", ea + i, eb + i, cost + i);
    floyd[ea[i]][eb[i]] = min(floyd[ea[i]][eb[i]], cost[i]);
    floyd[eb[i]][ea[i]] = floyd[ea[i]][eb[i]];
  }
  for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
  }
  if (floyd[0][n - 1] == (int) 1e9) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int a = ea[i], b = eb[i];
    if (floyd[0][a] + floyd[b][n - 1] + cost[i] == floyd[0][n - 1]) {
      g.add(a + a + 1, b + b, numeric_limits<int>::max());
    }
    if (floyd[0][b] + floyd[a][n - 1] + cost[i] == floyd[0][n - 1]) {
      g.add(b + b + 1, a + a, numeric_limits<int>::max());
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || i == n - 1) g.add(i + i, i + i + 1, numeric_limits<int>::max());
    else g.add(i + i, i + i + 1, 1);
  }
  int ans = g.max_flow();
  if (ans >= numeric_limits<int>::max()) puts("IMPOSSIBLE");
  else printf("%d\n", ans);
  return 0;
}