#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m;
vector< pair<int, int> > g[N];
int parent[N][22];
int cost[N][22][2];
int depth[N];
int from[N];
vector< tuple<int, int, int> > edges;

void dfs(int v = 0, int pv = 0) {
  for (pair<int, int> e : g[v]) {
    int to = e.first;
    int c = e.second;
    if (to == pv) continue;
    depth[to] = depth[v] + 1;
    cost[to][0][0] = c;
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
  int fmax1 = 0, smax1 = 0, fmax2 = 0, smax2 = 0;
  vector<int> fst, snd;
  for (int i = log; i >= 0; i--) {
    if (depth[x] - (1 << i) >= depth[y] && parent[x][i] > -1) {
      if (cost[x][i] > fmax1) {
        smax1 = fmax1;
        fmax1 = cost[x][i];
      } else {
        smax1 = max(smax1, cost[x][i]);
      }
      x = parent[x][i];
    }
    if (x == y) return smax1;
  }
  for (int i = log; i >= 0; i--) {
    if (parent[x][i] > -1 && parent[x][i] != parent[y][i]) {
      if (cost[x][i] > fmax1) {
        smax1 = fmax1;
        fmax1 = cost[x][i];
      } else smax1 = max(smax1, cost[x][i]);
      if (cost[y][i] > fmax2) {
        smax2 = fmax2;
        fmax2 = cost[y][i];
      } else smax2 = max(smax2, cost[y][i]);
      x = parent[x][i];
      y = parent[y][i];
    }
  }
  assert(parent[x][0] == parent[y][0]);
  if (cost[x][0] > fmax1) {
    smax1 = fmax1;
    fmax1 = cost[x][0];
  } else smax1 = max(smax1, cost[x][0]);
  if (cost[y][0] > fmax2) {
    smax2 = fmax2;
    fmax2 = cost[y][0];
  } else smax2 = max(smax2, cost[y][0]);
  if (fmax1 >= smax2 && fmax2 >= smax1) return min(fmax1, fmax2);
  else if (fmax1 < smax2) {
    return smax2;
  } else if (fmax2 < smax1) {
    return smax1;
  } else assert(0);
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
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    a--, b--;
    edges.push_back(make_tuple(c, a, b));
  }
  for (int i = 0; i < n; i++) from[i] = i;
  memset(parent, -1, sizeof parent);
  mst();
  dfs();
  for (int j = 1; 1 << j <= n; j++) {
    for (int i = 0; i < n; i++) {
      if (parent[i][j - 1] > -1) {
        parent[i][j] = parent[parent[i][j - 1]][j - 1];
        cost[i][j][0] = max(cost[parent[i][j - 1]][j - 1][0], cost[i][j - 1][0]);
        cost[i][j][1] = min(cost[parent[i][j - 1]][j - 1][0], cost[i][j - 1][0]);
      }
    }
  }
  int ans = lca_cost(0, n - 1);
  printf("%d\n", ans);
  return 0;
}