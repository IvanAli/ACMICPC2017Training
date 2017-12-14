#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, m;
int a[N], b[N], d[N], t[N];

int bin_search(int val, int w) {
  int low = 0, high = n - 1, mid;
  while (low < high) {
    mid = low + high >> 1;
    if (w == 0) {
      if (a[mid] > val) high = mid;
      else low = mid + 1;
    } else if (w == 1) {
      if (b[mid] > val) high = mid;
      else low = mid + 1;
    } else assert(0);
  }
  if (w == 0) {
    if (low < n && a[low] <= val) low = n;
  } else {
    if (low < n && b[low] <= val) low = n;
  }
  return low;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i > 0) a[i] = max(a[i], a[i - 1]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    if (i > 0) b[i] = max(b[i], b[i - 1]);
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", d + i);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", t + i);
  }
  for (int i = 0; i < m; i++) {
    int dd = bin_search(d[i], 0);
    int tt = bin_search(t[i], 1);
    if (dd > tt) puts("Constantine");
    else if (dd < tt) puts("Mike");
    else puts("Draw");
  }
  return 0;
}