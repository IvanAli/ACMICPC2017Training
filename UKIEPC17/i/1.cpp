#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int h;
  scanf("%d", &h);
  for (int i = 0; i < n; i++) {
    if (ans == -1) ans = a[i];
    else if (h % a[i] < h % ans) ans = a[i];
  }
  printf("%d\n", ans);
  return 0;
}