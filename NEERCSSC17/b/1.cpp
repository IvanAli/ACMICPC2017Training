#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n;
int a[N];
int nxt[N];
int used[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  nxt[n - 1] = n;
  for (int i = n - 2; i >= 0; i--) {
    nxt[i] = i + 1;
    while (nxt[i] < n && a[i] >= a[nxt[i]]) nxt[i] = nxt[nxt[i]];
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    int j = i;
    while (j < n) {
      if (!used[j]) printf("%d ", a[j]);
      used[j] = 1;
      j = nxt[j];
    }
    puts("");
  }
  return 0;
}