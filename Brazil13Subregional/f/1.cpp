#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
int a[N];
int pre[N];
int used[N];
int all;

bool ok(int i, int j, int t) {
  int ret = pre[j] - pre[i];
  return ret >= (all / 3) * t;
}

bool ok2(int i, int j, int t) {
  int ret = pre[j] - pre[i];
  return ret == (all / 3) * t;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    all += a[i];
    a[i + n] = a[i];
  }
  n += n;
  for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + a[i];
  if (all % 3 > 0) {
    puts("0");
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    int low = i + 1, high = i + n / 2, mid;
    while (low < high) {
      mid = low + high >> 1;
      if (ok(i, mid, 1)) high = mid;
      else low = mid + 1;
    }
    int cnt = 0;
    if (ok2(i, low, 1)) cnt++;
    int prv = low;
    low = i + 1, high = i + n / 2;
    while (low < high) {
      mid = low + high >> 1;
      if (ok(i, mid, 2)) high = mid;
      else low = mid + 1;
    }
    if (ok2(i, low, 2)) cnt++;
    if (cnt == 2) {
      ans++;
      used[i] = 1;
      used[i + n / 2] = 1;
      used[prv] = 1;
      used[prv + n / 2] = 1;
      used[low] = 1;
      used[low + n / 2] = 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}