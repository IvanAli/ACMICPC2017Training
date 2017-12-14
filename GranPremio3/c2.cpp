#include <bits/stdc++.h>

using namespace std;

int n, b;

int main() {
  while (scanf("%d %d", &n, &b) == 2) {
    n--;
    int cur = 1 << n;
    int sum = cur;
    bool ok = false;
    int which = -1;
    for (int i = n; i >= 0; i--) {
      if (sum >= b) {
        ok = true;
        which = i;
        break;
      }
      sum += cur;
      cur /= 2;
    }
    if (!ok) assert(0);
    int pos = sum - b + 1;
    int res = (1 << which) - 1 + pos;
    fprintf(stderr, "pos: %d res: %d\n", pos, res);
    printf("Instructions: ");
    while (res > 1) {
      if (res % 2 == 0) putchar('L');
      else putchar('R');
      res /= 2;
    }
    puts("");
  }
  return 0;
}
