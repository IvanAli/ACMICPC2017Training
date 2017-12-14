#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int a[N];
int mx[N], mn[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) mx[i] = max(mx[i - 1], a[i]);
      else mx[i] = a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) mn[i] = a[i];
      else mn[i] = min(mn[i + 1], a[i]);
    }
    int ans = 0;
    for (int i = 1; i + 1 < n; i++) {
      if (mx[i - 1] <= a[i] && mn[i + 1] >= a[i]) ans++; 
    }
    printf("%d\n", ans);
  }
  return 0;
}