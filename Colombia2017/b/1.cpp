#include <bits/stdc++.h>

using namespace std;

const int N = 35;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n, greater<int>());
  long long mul = 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long) a[i] * mul;
    mul *= a[i];
  }
  ans++;
  printf("%lld\n", ans);
  return 0;
}