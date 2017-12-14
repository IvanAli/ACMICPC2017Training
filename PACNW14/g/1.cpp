#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int T;
int n;
int a[N], b[N];
int lef, rig;
int one;

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i <= n + 1; i++) a[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      if (a[i] == 1) one = i;
    }
    for (int i = one - 1; i > 0; i--) {
      if (a[i - 1] < a[i]) { lef = i; break; }
    }
    for (int i = one + 1; i <= n; i++) {
      if (a[i + 1] < a[i]) { rig = i; break; }
    }
    int dlef = one - lef;
    int drig = rig - one;
    int lstep = 2, rstep = 2;
    for (int i = 1; i <= n; i++) b[i] = a[i];
    for (int i = 1; i <= n; i++) {
      if (a[one - 1] == 0 && a[one + 1] == 0) break;
      for (int j = 1; j <= n; j++) {
        if (j + 1 != one && a[j] > a[j - 1] && a[j] > a[j + 1] && a[j] > 0) {
          lstep++;
          a[j] = 0;
          break;
        }
      }
    }
    for (int i = 1; i <= n; i++) a[i] = b[i];
    for (int i = 1; i <= n; i++) {
      if (a[one - 1] == 0 && a[one + 1] == 0) break;
      for (int j = 1; j <= n; j++) {
        if (j - 1 != one && a[j] > a[j - 1] && a[j] > a[j + 1] && a[j] > 0) {
          rstep++;
          a[j] = 0;
          break;
        }
      }
    }
    if (n == 1) printf("Alice\n");
    else if (one == 1) {
      if (rstep % 2) printf("Alice\n");
      else printf("Bob\n");
    } else if (one == n) {
      if (lstep % 2) printf("Alice\n");
      else printf("Bob\n");
    } else {
      if (lstep % 2 && rstep % 2) {
        printf("Alice\n");
      } else if (lstep % 2 && rstep % 2 == 0) {
        if (drig <= dlef) printf("Alice\n");
        else printf("Bob\n");
      } else if (lstep % 2 == 0 && rstep % 2) {
        if (dlef <= drig) printf("Alice\n");
        else printf("Bob\n");
      } else {
        printf("Bob\n"); 
      }
    }
  }
  return 0;
}
