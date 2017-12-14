#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
int x[N], y[N], z[N];
set<tuple<int, int, int> > st;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", x + i, y + i, z + i);
  }
  for (int i = 1; i < n; i++) {
    int dx = x[i] - x[0];
    int dy = y[i] - y[0];
    int dz = z[i] - z[0];
    if (dx < 0) {
      dx = -dx;
      dy = -dy;
      dz = -dz;
    }
    if (dx == 0) {
      if (dy < 0) {
        dy = -dy;
        dz = -dz;
      }
    }
    if (dx == 0 && dy == 0) {
      if (dz < 0) {
        dz = -dz;
      }
    }
    int g = __gcd(dx, dy);
    g = __gcd(g, dz);
    dx /= g;
    dy /= g;
    dz /= g;
    st.insert(make_tuple(dx, dy, dz));
  }
  int ans = (int) st.size();
  printf("%d\n", ans);
  return 0;
}