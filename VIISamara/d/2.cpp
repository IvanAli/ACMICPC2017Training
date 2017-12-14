#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int M = 1005;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, v;
int cc;
vector< pair<int, int> > g[N];
char grid[M][M];
int parent[N][22];
int cost[N][22];
int depth[N];
int used[M][M];
int d[M][M];
int d_com[N];
bool seen[N];
int from[N];
vector< tuple<int, int, int> > edges;

void dfs(int x, int y, int cc) {
  used[x][y] = cc;
  for (int k = 0; k < 4; k++) {
    int xk = x + dx[k];
    int yk = y + dy[k];
    if (xk < 0 || xk >= n || yk < 0 || yk >= m) continue;
    if (!used[xk][yk] && grid[xk][yk] == 'F') {
      dfs(xk, yk, cc);
    }
  }
}

void bfs(int x, int y) {
  queue< pair<int, int> > q;
  q.emplace(x, y);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) d[i][j] = -1;
  int w = used[x][y];
  assert(w > 0);
  seen[w] = true;
  d[x][y] = 0;
  while (!q.empty()) {
    tie(x, y) = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
      int xk = x + dx[k];
      int yk = y + dy[k];
      if (xk < 0 || xk >= n || yk < 0 || yk >= m) continue;
      if (grid[x][y] == 'F') {
        if (grid[xk][yk] == 'F') {
          if (d[xk][yk] == -1 || d[x][y] < d[xk][yk]) {
            d[xk][yk] = d[x][y];
            q.emplace(xk, yk);
          }
        } else {
          if (d[xk][yk] == -1 || d[x][y] + 1 < d[xk][yk]) {
            d[xk][yk] = d[x][y] + 1;
            q.emplace(xk, yk);
          }
        }
      } else {
        if (d[xk][yk] == -1 || d[x][y] + 1 < d[xk][yk]) {
          d[xk][yk] = d[x][y] + 1;
          q.emplace(xk, yk);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used[i][j]) {
        d_com[used[i][j]] = d[i][j];
      }
    }
  }
  for (int i = 1; i <= cc; i++) {
    if (i <= w) continue;
    edges.emplace_back(d_com[i], w, i);
  }
}

void dfs(int v = 1, int pv = 1) {
  for (pair<int, int> e : g[v]) {
    int to = e.first;
    int c = e.second;
    if (to == pv) continue;
    depth[to] = depth[v] + 1;
    cost[to][0] = c;
    parent[to][0] = v;
    dfs(to, v);
  }
}

int lca_cost(int x, int y) {
  if (x == y) return 0;
  if (depth[x] < depth[y]) swap(x, y);
  int log = 1;
  while (1 << log <= depth[x]) log++;
  log--;
  int ret = 0;
  for (int i = log; i >= 0; i--) {
    if (depth[x] - (1 << i) >= depth[y] && parent[x][i] > -1) {
      ret = max(ret, cost[x][i]);
      x = parent[x][i];
    }
    if (x == y) return ret;
  }
  for (int i = log; i >= 0; i--) {
    if (parent[x][i] > -1 && parent[x][i] != parent[y][i]) {
      ret = max(ret, cost[x][i]);
      ret = max(ret, cost[y][i]);
      x = parent[x][i];
      y = parent[y][i];
    }
  }
  assert(parent[x][0] == parent[y][0]);
  ret = max(ret, cost[x][0]);
  ret = max(ret, cost[y][0]);
  return ret;
//  return parent[x][0];
}

void answer() {
  puts("Hello, Deimos!");
}

void err() {
  puts("Dire victory");
}

int find(int x) {
  if (x == from[x]) return x;
  return from[x] = find(from[x]);
}

void mst() {
  sort(edges.begin(), edges.end());
  for (auto it : edges) {
    int w, a, b; tie(w, a, b) = it;
    int x = find(a), y = find(b);
    if (x != y) {
      g[x].emplace_back(y, w);
      g[y].emplace_back(x, w);
      from[x] = y;
    }
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &v);
  int xs, ys, xd, yd;
  scanf("%d %d %d %d", &xs, &ys, &xd, &yd);
  xs--, ys--, xd--, yd--;
  for (int i = 0; i < n; i++) {
    scanf("%s", grid[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j] && grid[i][j] == 'F') {
        dfs(i, j, ++cc);
      }
    }
  }
  if (!used[xs][ys]) {
    used[xs][ys] = ++cc;
  }
  if (!used[xd][yd]) {
    used[xd][yd] = ++cc;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (used[i][j] > 0 && !seen[used[i][j]]) {
        bfs(i, j);
      }
    }
  }
  for (int i = 1; i <= cc; i++) from[i] = i;
  memset(parent, -1, sizeof parent);
  mst();
  dfs();
  for (int j = 1; 1 << j < N; j++) {
    for (int i = 1; i <= cc; i++) {
      if (parent[i][j - 1] > -1) {
        parent[i][j] = parent[parent[i][j - 1]][j - 1];
        cost[i][j] = max(cost[parent[i][j - 1]][j - 1], cost[i][j - 1]);
      }
    }
  }
  int ans = lca_cost(used[xs][ys], used[xd][yd]);
  if (ans <= v) answer();
  else err();
  return 0;
}