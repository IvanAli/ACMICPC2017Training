#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

int n, q;
unordered_map<long long, int> ma;
char s[31], a[31], b[31];
int res[N];
bool pal[31][31];
int segtree[N << 2];

long long hsh(char *s) {
  long long ret = 0;
  for (int i = 0; s[i]; i++) {
    ret = ret * 4 + s[i] - 'a' + 1;
  }
  return ret;
}

int calc(char *s) {
  int n = strlen(s);
  int ret = 0;
  for (int i = 0; i < n; i++) pal[i][i] = 1;
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len - 1;
      if (len == 2) pal[i][j] = s[i] == s[j];
      else pal[i][j] = (s[i] == s[j]) && pal[i + 1][j - 1];
    }
  }
  for (int i = 0; i < n; i++) for (int j = i; j < n; j++) ret += pal[i][j];
  return ret;
}

class segment_tree {
  public:

  void build(int id = 1, int l = 0, int r = n) {
    if (l + 1 == r) {
      segtree[id] = l;
      return;
    }
    int mid = l + r >> 1;
    build(id + id, l, mid);
    build(id + id + 1, mid, r);
    int lf = segtree[id + id];
    int rg = segtree[id + id + 1];
    if (res[lf] >= res[rg]) segtree[id] = lf;
    else segtree[id] = rg;
  }

  int query(int x, int y, int id = 1, int l = 0, int r = n) {
    if (l >= y || r <= x) return -1;
    if (l >= x && r <= y) return segtree[id];
    int mid = l + r >> 1;
    int lf = query(x, y, id + id, l, mid);
    int rg = query(x, y, id + id + 1, mid, r);
    if (lf == -1) return rg;
    if (rg == -1) return lf;
    if (res[lf] >= res[rg]) return lf;
    return rg;
  }
};

int main() {
  int T; scanf("%d", &T);
  segment_tree segtree;
  while (T--) {
    scanf("%d %d", &n, &q);
    ma.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      long long h = hsh(s);
      if (ma.count(h)) assert(0);
      ma[h] = i;
      res[i] = calc(s);
    }
    segtree.build();
    while (q--) {
      scanf("%s %s", a, b);
      long long ha = hsh(a);
      long long hb = hsh(b);
      if (!ma.count(ha)) assert(0);
      if (!ma.count(hb)) assert(0);
      int ia = ma[ha], ib = ma[hb];
      if (ia > ib) swap(ia, ib);
      int ans = segtree.query(ia, ib + 1);
      assert(ans > -1);
      printf("%d\n", ans + 1);
    }
  }
  return 0;
}