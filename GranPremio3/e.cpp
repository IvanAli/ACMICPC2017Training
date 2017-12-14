#include <bits/stdc++.h>

using namespace std;

int T;
int n;

int main() {
  while (scanf("%d", &n) && n > 0) {
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) for (int k = j; k <= n; k++) {
      if (i * i + j * j == k * k) ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
