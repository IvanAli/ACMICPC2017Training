#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n;
int T;
int a[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i + 1);
    a[0] = a[1];
    int ans = 0;
    int cur = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] > a[i - 1] && !ok) {
        cur = 1;
        ok = true;
      } else if (a[i] < a[i - 1]) {
        ok = false;
      }
      cur++; 
      ans = max(ans, cur);
    }
    printf("%d\n", ans);
  }
  return 0;
}
