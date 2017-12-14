#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += a[i];
  }
  ans += (long long) a[0] * (n - 2);
  if (ans < 0) ans = -ans;
  printf("%lld\n", ans);
  return 0;
}