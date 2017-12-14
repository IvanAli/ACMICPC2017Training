#include <bits/stdc++.h>

using namespace std;
                 
const int MAX = 14;
const int N = 200010;
const int mod = (int) 1e9 + 7;

int n, q;
vector<int> graph[N];
char s[10];
int tin[N], tout[N], which[N];
int tim;
int segtree[N + N][MAX];
int val[N];
int prime[MAX];

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void dfs(int v = 0, int pv = 0) {
  tin[v] = tim;
  which[tim] = v;
  tim++;
  for (int to : graph[v]) {
    if (to == pv) continue;
    dfs(to, v);
  }
  tout[v] = tim;
  which[tim] = v;
  tim++;
}

void build(int id = 1, int l = 0, int r = tim) {
  if (l + 1 == r) {
    int aux = val[which[l]];
    for (int i = 2; (long long) i * i <= aux; i++) {
      while (aux % i == 0) {
        segtree[id][i]++;
        aux /= i;
      }
    }
    if (aux > 1) segtree[id][aux]++;
    return;
  }
  int mid = l + r >> 1;
  build(id + id, l, mid);
  build(id + id + 1, mid, r);
  for (int i = 2; i < MAX; i++) segtree[id][i] = segtree[id + id][i] + segtree[id + id + 1][i];
}

vector<int> query(int x, int y, int id = 1, int l = 0, int r = tim) {
  vector<int> ret;
  if (l >= y || r <= x) {
    for (int i = 2; i < MAX; i++) ret.push_back(0);
    return ret;
  }
  if (l >= x && r <= y) {
    for (int i = 2; i < MAX; i++) ret.push_back(segtree[id][i]);
    return ret;
  }
  int mid = l + r >> 1;
  vector<int> ql = query(x, y, id + id, l, mid);
  vector<int> qr = query(x, y, id + id + 1, mid, r);
  ret = ql;
  assert((int) ql.size() == (int) qr.size());
  for (int i = 0; i < (int) ql.size(); i++) {
    ret[i] += qr[i];
  }
  return ret;
}

void update(int p, int v, int id = 1, int l = 0, int r = tim) {
  if (l + 1 == r) {
    memset(prime, 0, sizeof prime);
    int aux = v;
    for (int i = 2; (long long) i * i <= aux; i++) {
      while (aux % i == 0) {
        prime[i]++;
        aux /= i;
      }
    }
    if (aux > 1) prime[aux]++;
    for (int i = 2; i < MAX; i++) segtree[id][i] += prime[i];
    return;
  }
  int mid = l + r >> 1;
  if (p < mid) update(p, v, id + id, l, mid);
  else update(p, v, id + id + 1, mid, r);
  for (int i = 2; i < MAX; i++) segtree[id][i] = segtree[id + id][i] + segtree[id + id + 1][i];
}

int power(int x, int e) {
  int ret = 1, res = x;
  while (e) {
    if (e & 1) ret = mul(ret, res);
    res = mul(res, res);
    e >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i + 1 < n; i++) {
    int a, b; scanf("%d %d", &a, &b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < n; i++) scanf("%d", val + i);
  dfs();
  scanf("%d", &q);
  build();
  while (q--) {
    scanf("%s", s);
    if (s[0] == 'S') {
      int x, y; scanf("%d %d", &x, &y);
      update(tin[x], y);
      update(tout[x], y);
    } else if (s[0] == 'R') {
      int x; scanf("%d", &x);
      vector<int> g = query(tin[x], tout[x] + 1);
      int divs = 1;
      int mult = 1;
      for (int i = 0; i < (int) g.size(); i++) {
        int k = i + 2;
        divs = mul(divs, g[i] / 2 + 1);
        mult = mul(mult, power(k, g[i] / 2));
      }
      printf("%d %d\n", mult, divs);
    } else assert(0);
  }
  return 0;
}