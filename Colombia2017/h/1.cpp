#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    putchar('*');
    for (int j = 0; j < n - 2; j++) {
      if (i + 1 < n) putchar(' ');
      else putchar('*');
    }
    putchar('*');
    putchar(' ');
    putchar('*');
    for (int j = 0; j < n - 2; j++) {
      if (i == 0) putchar('*');
      else putchar(' ');
    }
    putchar('*');
    puts("");
  }
  return 0;
}