#include <bits/stdc++.h>

using namespace std;


int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    if (n % 3 == 0) {
      for (int i = 0; i < 3; i++) {
        if (i > 0) putchar(' ');
        printf("%lld", n / 3);
      }
      puts("");
    } else if (n % 4 == 0) {
      for (int i = 0; i < 2; i++) {
        printf("%lld ", n / 4);
      }
      printf("%lld\n", n / 2);
    } else {
      puts("IMPOSSIBLE");
    }
  }
  return 0;
}