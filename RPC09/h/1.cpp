#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
long long s;
long long a[N];

int main() {
  while (scanf("%d %lld", &n, &s) == 2) {
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    long long sum = 0;
    bool ok = false;
    int j = 0, r = -1;
    for (int i = 0; i < n; i++) {
      while (j < n && sum > s) {
        sum -= a[j];
        j++;
      }
      if (sum == s) {
        ok = true;
        r = i - 1;
        break;
      }
      sum += a[i];
    }
    while (j < n && sum > s) {
      sum -= a[j];
      j++;
    }
    if (!ok && sum == s) {
      ok = true;
      r = n - 1;
    }
    if (ok) printf("%d %d\n", j + 1, r + 1);
    else puts("-1");
  }
  return 0;
}