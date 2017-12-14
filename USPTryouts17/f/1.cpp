#include <bits/stdc++.h>

using namespace std;

int r;

int main() {
  scanf("%d", &r);
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    int x, y; scanf("%d %d", &x, &y);
    for (int j = 1; j <= 10; j++) {
      if (x * x + y * y <= j * j * r * r) {
        ans += 10 - j + 1;
        break;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}