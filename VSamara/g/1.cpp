#include <bits/stdc++.h>

using namespace std;

const int N = 2222;

int a[N], ans[N];
int p[N];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int k, n;
  scanf("%d %d", &k, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[i] = i;
  }
  sort(p, p + n, [&](const int i, const int j) {
    return a[i] < a[j];
  });
  for (int i = 0; i < n; i++) {
    int mn = min(a[p[i]], k);
    ans[p[i]] = mn;
    k -= mn;
  }         
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}