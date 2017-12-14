#include <bits/stdc++.h>

using namespace std;

const int N = 3 * 10000010;
const int mod = 3 * 10000000;

int n, m, q;
int a[N];
int have[N];

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < m; i++) scanf("%d", a + i);
  for (int i = m; i < n; i++) {
    a[i] = (a[i - m] + a[i - m + 1]) % mod;
  }
  for (int i = 0; i < n; i++) have[a[i]]++;
  for (int i = 1; i < N; i++) have[i] += have[i - 1];
  while (q--) {
    int b; scanf("%d", &b);
    int low = 0, high = N - 1, mid;
    while (low < high) {
      mid = low + high >> 1;
      if (have[mid] >= b) high = mid;
      else low = mid + 1;
    }
    printf("%d\n", low);
  }
  return 0;
}