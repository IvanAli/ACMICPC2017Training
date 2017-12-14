#include <bits/stdc++.h>

using namespace std;

const int N = 345;

int n, m;

struct node {
  int a[N][N];
  bool operator < (const node &other) const {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] != other.a[i][j]) return true;
    return false;
  }
  bool operator == (const node &other) const {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] != other.a[i][j]) return true;
    return false;
  }
};

bool equal(const node &a, const node &b) {
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a.a[i][j] != b.a[i][j]) return false;
  return true;
}

node s, t;
map<node, int> used;
int tmp[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) s.a[i][j] = i * m + j + 1;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &t.a[i][j]);
  queue<node> q;
  q.push(s);
  used[s] = 0;
  while (!q.empty()) {
    node v = q.front(); q.pop();
    int d = used[v];
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
      swap(v.a[i], v.a[j]);
      if (!used.count(v)) {
        used[v] = d + 1;
        q.push(v);
      }
      if (equal(v, t)) {
        printf("%d\n", d + 1);
        return 0;
      }
      swap(v.a[i], v.a[j]);
    }
    for (int i = 0; i < m; i++) for (int j = i + 1; j < m; j++) {
      for (int k = 0; k < n; k++) tmp[k] = v.a[k][i];
      for (int k = 0; k < n; k++) v.a[k][i] = v.a[k][j];
      for (int k = 0; k < n; k++) v.a[k][j] = tmp[k];
      if (!used.count(v)) {
        used[v] = d + 1;
        q.push(v);
      }
      if (equal(v, t)) {
        printf("%d\n", d + 1);
        return 0;
      }
      for (int k = 0; k < n; k++) tmp[k] = v.a[k][i];
      for (int k = 0; k < n; k++) v.a[k][i] = v.a[k][j];
      for (int k = 0; k < n; k++) v.a[k][j] = tmp[k];
    }
  }
  if (used.count(t)) printf("%d\n", used[t]);
  else printf("*\n");
  return 0;
}