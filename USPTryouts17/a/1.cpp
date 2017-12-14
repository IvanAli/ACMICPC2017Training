#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, m, k;
int used[N];
vector<int> graph[N];

bool dfs(int v, int c) {
  if (c > k) c = 1;
  used[v] = c;
  for (int to : graph[v]) {
    if (used[to]) {
      if (used[v] == used[to]) return false;
      continue;
    }
    if (!dfs(to, c + 1)) return false;
  }
  return true;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    int a, b; scanf("%d %d", &a, &b); a--, b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      if (!dfs(i, 1)) {
        puts("-1");
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%d\n", used[i]);
  return 0;
}