#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int T;
int n;
int a[N][N];
int all[N];
int have[N];
int x[N];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) have[i] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", a[i] + j);
    for (int i = 0; i < n; i++) all[i] = 0;
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    long long ans = 0;
    for (int k = n - 1; k >= 0; k--) {
      have[x[k]] = 1;
      for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (i == j) continue;
          a[i][j] = min(a[i][j], a[i][x[k]] + a[x[k]][j]);
        if (have[i] && have[j]) {
        
          ans += a[i][j];
//          fprintf(stderr, "adding (%d ,%d): %d\n", i, j, a[i][j]);
//          fprintf(stderr, "tried %d %d %d .. %d %d\n", i, x[k], j, a[i][x[k]], a[x[k]][j]);
        }
      }
//      have[x[k]] = 1;
//      fprintf(stderr, "ans: %lld\n", ans);
    }
    printf("%lld\n", ans);
  }
  return 0;
}