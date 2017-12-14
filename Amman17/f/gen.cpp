#include <bits/stdc++.h>

using namespace std;


int main() {
  srand(time(0));
  int t = 123;
  printf("%d\n", t);
  while (t--) {
    int n = rand() % 15 + 1;
    int k = rand() % n + 1;
    printf("%d %d\n", n, k);
    for (int i = 0; i < n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", rand() % n + 1);
    }
    puts("");
  }
  return 0;
}