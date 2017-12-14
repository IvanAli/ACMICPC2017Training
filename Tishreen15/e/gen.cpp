#include <bits/stdc++.h>

using namespace std;

int a[5];

int main() {
  int T = 123456;
  srand(time(0));
  FILE *fout = fopen("out", "w+");
  printf("%d\n", T);
  for (int tc = 0; tc < T; tc++) {
    for (int i = 0; i < 5; i++) a[i] = rand() % 55 + 1;
    sort(a, a + 5);
    for (int i = 1; i < 5; i++) {
      if (a[i] < a[i - 1]) assert(0);
    }
    fprintf(fout, "Case %d: ", tc + 1);
    for (int i = 0; i < 5; i++) {
      if (i > 0) fprintf(fout, " ");
      fprintf(fout, "%d", a[i]);
    }
    fprintf(fout, "\n");
    for (int i = 0; i < 5; i++) for (int j = i + 1; j < 5; j++) printf("%d ", a[i] + a[j]);
    puts("");
  }
  return 0;
}