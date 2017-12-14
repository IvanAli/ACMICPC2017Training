#include <bits/stdc++.h>

using namespace std;

const int N = 2345;

int n;
vector<pair<int, int> > graph[N];
int from[N];
vector<pair<int, pair<int, int> > > edges;
int d[N][N];

int find(int x) {
  return (x == from[x] ? x : from[x] = find(from[x]));
}

bool dfs(int s, int v, int pv, int sum = 0) {
  for (auto pr : graph[v]) {
    int to = pr.first, w = pr.second;
    if (to == pv) continue;
    if (d[s][to] != sum + w) return false;
    if (!dfs(s, to, v, sum + w)) return false;
  }
  return true;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", d[i] + j);
    edges.push_back(make_pair(d[i][j], make_pair(i, j)));
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (i == j) {
      if (d[i][j] > 0) {
        puts("NO");
        return 0;
      }
    } else {
      if (d[i][j] != d[j][i] || d[i][j] == 0) {
        puts("NO");
        return 0;
      }
    }
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; i++) from[i] = i;
  for (int i = 0; i < (int) edges.size(); i++) {
    int w = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
    int x = find(a), y = find(b);
    if (x != y) {
      from[x] = y;
      graph[a].push_back(make_pair(b, w));
      graph[b].push_back(make_pair(a, w));
    }
  }
  for (int i = 0; i < n; i++) {
    if (!dfs(i, i, i)) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}