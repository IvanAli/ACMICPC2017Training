#include <bits/stdc++.h>

using namespace std;

const int N = 12345;
long long a[2][N];
long long row[2 * N], col[2 * N];
long long elem[2 * N];

int main() {
  int n, r, c;                       
  int test = 0;
  while (scanf("%d %d %d", &n, &r, &c) && n + r + c > 0) {
    printf("Case %d:\n", ++test);
    int mn = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        scanf("%lld", a[i] + j);
      }
    }
    r--;
    c--;
    int sz = 0;
    if (r == 0) {
      for (int j = c; j < n; j++) {
        elem[sz] = a[0][j];
        row[sz] = 0;
        col[sz] = j;
        sz++;
      }
      for (int j = n - 1; j >= 0; j--) {
        elem[sz] = a[1][j];
        row[sz] = 1;
        col[sz] = j;
        sz++;
      }
      for (int j = 0; j < c; j++) {
        elem[sz] = a[0][j];
        row[sz] = 0;
        col[sz] = j;
        sz++;
      }
    } else if (r == 1) {
      for (int j = c; j >= 0; j--) {
        elem[sz] = a[1][j];
        row[sz] = 1;
        col[sz] = j;
        sz++;
      }
      for (int j = 0; j < n; j++) {
        elem[sz] = a[0][j];
        row[sz] = 0;
        col[sz] = j;
        sz++;
      }
      for (int j = n - 1; j > c; j--) {
        elem[sz] = a[1][j];
        row[sz] = 1;
        col[sz] = j;
        sz++;
      }
    }
    for (int i = 0; i < sz; i++) {
      if (elem[i] < elem[mn]) mn = i;
    }
    if (row[mn] == 0) {
      puts("INVALID");
      continue;
    }
    assert(sz == 2 * n);
    long long times = elem[mn] * sz + mn;
    a[row[mn]][col[mn]] = times;
    for (int i = mn - 1; i >= 0; i--) a[row[i]][col[i]] -= elem[mn] + 1;
    for (int i = mn + 1; i < sz; i++) a[row[i]][col[i]] -= elem[mn];
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        if (j > 0) putchar(' ');
        assert(a[i][j] >= 0);
        printf("%lld", a[i][j]);
      }
      puts("");
    }
  }
  return 0;
}