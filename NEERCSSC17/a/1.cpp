#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n;
int l[N], r[N];
int cc = 1;
int used[N];
int first[N], last[N];

void dfs(int v) {
  used[v] = cc;
  if (l[v] > -1) {
    if (!used[l[v]]) {
      first[cc] = l[v];
      dfs(l[v]);
    }
  }
  if (r[v] > -1) {
    if (!used[r[v]]) {
      last[cc] = r[v];
      dfs(r[v]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
    l[i]--, r[i]--;
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      first[cc] = i;
      last[cc] = i;
      dfs(i);
      cc++;
    }
  }
  for (int i = 1; i + 1 < cc; i++) {
    l[first[i + 1]] = last[i];
    r[last[i]] = first[i + 1];
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", l[i] + 1, r[i] + 1);
  puts("");
  return 0;
}