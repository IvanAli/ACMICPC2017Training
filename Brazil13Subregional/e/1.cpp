#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int n, k;
int have[N];

int main() {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < n; i++) {
    int foo; scanf("%d", &foo);
    have[foo]++;
  }
  bool ok = false;
  for (int i = 1; i <= k; i++) {
    if (!have[i]) {
      if (ok) putchar(' ');
      printf("%d", i);
      ok = true;
    }
  }
  if (!ok) printf("*");
  puts("");
  return 0;
}