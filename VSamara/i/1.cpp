#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector<int> g[N];
int color[N];

int dfs(int v = 0, int pv = 0) {
  int mn = (int) 1e9;
  for (int to : g[v]) {
    if (to == pv) continue;
    mn = min(mn, dfs(to, v));
  }
  if (mn == (int) 1e9) {
    return 0;
  }
  if (mn == 0) {
    color[v] = 1;
    return 1;
  }
  if (mn == 1) {
    return 2;
  }
  if (v == 0) color[v] = 1;
  return 0;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i + 1 < n; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs();
  if (n == 1) color[0] = 1;
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", color[i]);
  }
  puts("");
  return 0;
}