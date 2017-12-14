#include <bits/stdc++.h>

using namespace std;


int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (pal(a[i])) where[i] = 1;
    if (luc(a[i])) where[i] = 2;
    if (pal_luc(a[i])) where[i] = 3;
    if (where[i] == 0) {
      puts("No");
      return 0;
    }
    for (int j = 0; j <= 20; j++) {
      int k = i - j;
      if (k < 0) break;
      if (where[k] == 1 || where[k] == 2) {
        int v = where[k] + n - 1;
        graph[i].push_back(v);
        graph[v].push_back(i);
      }
  }

  return 0;
}