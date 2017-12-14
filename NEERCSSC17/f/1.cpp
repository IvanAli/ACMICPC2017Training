#include <bits/stdc++.h>

using namespace std;

const int N = 555;

int n, k, m, a;
int have[N], last[N];
int can[N];
int ans[N];

int main() {
  scanf("%d %d %d %d", &n, &k, &m, &a);
  for (int i = 0; i < a; i++) {
    int b; scanf("%d", &b);
    b--;
    have[b]++;
    last[b] = i;
  }
  for (int i = 0; i < n; i++) {
    can[i] = i;
  }
  sort(can, can + n, [&](const int i, const int j) {
    if (have[i] == have[j]) {
      return last[i] < last[j];
    }
    return have[i] > have[j];
  });
  for (int i = 0; i < n; i++) {
    int ci = can[i];
    int aux = m - a;
    if (have[ci] == 0) {
      if (have[can[k - 1]] == 0 && m - a > 0) {
        ans[ci] = 2;
        continue;
      }
      if (have[can[k - 1]] == 0 && m - a == 0) {
        ans[ci] = 3;
        continue;
      }
    }
    if (i < k) {
      int rem = k - i;
      int win = 0;
      for (int j = 0; j < rem; j++) {
        if (i + j + 1 >= n) break;
        int cj = can[i + j + 1];
        assert(have[ci] >= have[cj]);
        int mn = have[ci] - have[cj] + 1;
        if (mn <= aux) {
          win++;
        }
        aux -= min(aux, mn);
      }
      if (win == rem) {
        ans[ci] = 2;
      } else {
        ans[ci] = 1;
      }
    } else {
      int need = have[can[k - 1]] - have[ci] + 1;
      if (need <= aux) {
        ans[ci] = 2;
      } else {
        ans[ci] = 3;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}