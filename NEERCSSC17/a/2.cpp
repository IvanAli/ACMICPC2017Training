#include <bits/stdc++.h>

using namespace std;

const int N = 123;

int n;
int l[N], r[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
    l[i]--, r[i]--;
  }
  int s = -1, e = -1;
  for (int i = 0; i < n; i++) {
    if (l[i] == -1) {
      s = i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (r[i] == -1) {
      if (s != i) {
        e = i;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (r[i] == -1 && e != i) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (l[j] == -1 && j != s) {
          if (i == s && j == e) continue;
          r[i] = j;
          l[j] = i;
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", l[i] + 1, r[i] + 1);
  puts("");
  return 0;
}