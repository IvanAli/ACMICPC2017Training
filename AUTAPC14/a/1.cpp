#include <bits/stdc++.h>

using namespace std;

bool ok(long long mid, int n) {
  return mid * (mid + 1) / 2 <= n + 3;
}

int main() {
  int n; scanf("%d", &n);
  long long low = 3, high = 14150, mid;
  while (low < high) {
    mid = low + high + 1 >> 1;
    if (ok(mid, n)) low = mid;
    else high = mid - 1;
  }
  if (ok(low, n)) printf("%lld\n", max(0ll, low - 2));
  else puts("0");
  return 0;
}