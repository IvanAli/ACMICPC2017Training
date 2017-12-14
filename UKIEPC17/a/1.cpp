#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n;
int h[N], st[N], fin[N];

bool ok(int x) {
  for (int i = 0; i < n; i++) {
    int y = x % h[i];
    if (st[i] < fin[i]) {
      if (y > st[i] && y < fin[i]) return false;
    } else {
      if (y > st[i] || y < fin[i]) return false; 
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", h + i, st + i, fin + i);
    mx = max(mx, h[i]);
  }
  for (int i = 0; i <= 1825 * mx; i++) {
    if (ok(i)) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("impossible");
  return 0;
}