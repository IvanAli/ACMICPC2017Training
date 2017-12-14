#include <bits/stdc++.h>

using namespace std;

const int N = 12345;

int n, q;
map<string, int> ma;
char s[33], a[33], b[33];
int res[N];

int calc(string &s) {
  int n = s.size();
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool ok = true;
      for (int k = 0; k <= j - i; k++) {
        if (s[i + k] != s[j - k]) {
          ok = false;
          break;
        }
      }
      ret += ok;
    }
  } 
  return ret;
}

class segment_tree {
  public:
  vector<int> segtree;
  segment_tree(int n) {
    segtree.resize(4 * n);
  }
  
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
  while (T--) {
    scanf("%d %d", &n, &q);
    segment_tree segtree(n);
    ma.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      string si = string(s);
      ma[si] = i;
      res[i] = calc(si);
    }
    segtree.build();
    while (q--) {
      scanf("%s %s", a, b);
      string sa = string(a);
      string sb = string(b);
      int ia = ma[sa], ib = ma[sb];
      int ans = segtree.query(ia, ib + 1);
      printf("%d\n", ans + 1);
    }
  }
  return 0;
}