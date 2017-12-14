#include <bits/stdc++.h>

using namespace std;

const int N = 2345;

int n, k;
int a[N];

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n, greater<int>());
  int ans = 0;
  for (int i = 0; i < n; i += k) {
    ans += (a[i] - 1) * 2;
  }
  printf("%d\n", ans);
  return 0;
}