#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int a[N];

int main() {
  int T, n, m; 
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
      if (a[i] > -1) {
        int cur = a[i] - 1;
        if (cur < 0) cur += m;
        for (int j = i - 1; j >= 0; j--) {
          if (a[j] == -1) {
            a[j] = cur;
          }
          cur--;
          if (cur < 0) cur += m;
        }
        cur = a[i] + 1;
        if (cur >= m) cur -= m;
        for (int j = i + 1; j < n; j++) {
          if (a[j] == -1) {
            a[j] = cur;
          }
          cur++;
          if (cur >= m) cur -= m;
        }
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", a[i]);
    }
    puts("");
  }
  return 0;
}