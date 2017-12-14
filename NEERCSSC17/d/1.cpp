#include <bits/stdc++.h>

using namespace std;

int n, t;

int main() {
  scanf("%d %d", &n, &t);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    if (a <= t - n + i) ans++;
  }
  printf("%d\n", ans);
  return 0;
}