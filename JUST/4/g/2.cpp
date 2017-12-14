#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int a[N];

template <typename T>
class fenwick {
  public:
  vector<T> fen;

  fenwick(int N) {
    fen.resize(N);
  }

  void add(int i, T val) {
    while (i < N) {
      fen[i] += val;
      i += i & -i;
    }
  }

  T get(int i) {
    T ret = 0;
    while (i > 0) {
      ret += fen[i];
      i -= i & -i;
    }
    return ret;
  }

  T get(int i, int j) {
    T ret = get(j);
    if (i > 0) ret -= get(i - 1);
    return ret;
  }

  void clear() {
    fill(fen.begin(), fen.end(), 0);
  }
};

int main() {
  int T;
  scanf("%d", &T);
  fenwick<int> fen_ls(N);
  fenwick<int> fen_gt(N);
  while (T--) {
    int n; scanf("%d", &n);
    fen_ls.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
      fen_gt.add(a[i], 1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int ls = fen_ls.get(1, a[i]);
      int gt = fen_gt.get(a[i], N - 1);
      if (ls == i && gt == n - i && i > 0 && i < n - 1) ans++;
      fen_ls.add(a[i], 1);
      fen_gt.add(a[i], -1);
    }
    printf("%d\n", ans);
  }
  return 0;
}